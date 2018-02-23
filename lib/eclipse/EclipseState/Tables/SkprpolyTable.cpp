/*
  Copyright 2015 SINTEF ICT, Applied Mathematics.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <opm/parser/eclipse/Deck/DeckKeyword.hpp>
#include <opm/parser/eclipse/EclipseState/Tables/SkprpolyTable.hpp>
#include <opm/parser/eclipse/Parser/ParserKeywords/S.hpp>


namespace Opm{

    SkprpolyTable::SkprpolyTable(const Opm::DeckKeyword& table)
    {
        using namespace ParserKeywords;

        const DeckRecord& record0 = table.getRecord(0);
        m_table_number = record0.getItem<SKPRPOLY::TABLE_NUMBER>().get< int >(0);
        m_reference_concentration = record0.getItem<SKPRPOLY::REF_CONC>().getSIDouble(0);
        m_x_points = table.getRecord(1).getItem<SKPRPOLY::THROUGHPUT>().getSIDoubleData();
        const size_t num_cols = m_x_points.size();

        if (table.size() != num_cols + 3) {
            const std::string msg = "SKPRPOLY table " + std::to_string(m_table_number)
                                    + " does not have enough records!";
            throw std::invalid_argument(msg);
        }

        m_y_points = table.getRecord(2).getItem<SKPRPOLY::VELOCITY>().getSIDoubleData();
        const size_t num_rows = m_y_points.size();

        for (size_t i = 3; i < table.size(); ++i) {
            const DeckRecord& record_i = table.getRecord(i);
            const std::vector<double>& data_i = record_i.getItem<SKPRPOLY::PRESSURE>().getSIDoubleData();
            if (data_i.size() != num_rows) {
                const std::string msg = "SKPRPOLY table " + std::to_string(m_table_number)
                                      + " record " + std::to_string(i)
                                      + " does not have correct number of data ";
                throw std::invalid_argument(msg);
            }
        }
    }

    size_t SkprpolyTable::getTableNumber() const
    {
        return m_table_number;
    }
}
