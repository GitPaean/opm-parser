/*
  Copyright (C) 2018 Statoil ASA

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

#ifndef OPM_PARSER_SKPRWAT_TABLE_HPP
#define OPM_PARSER_SKPRWAT_TABLE_HPP

#include <opm/parser/eclipse/EclipseState/Tables/Simple2DTable.hpp>
namespace Opm {

    class DeckKeyword;

    class SkprwatTable : public Simple2DTable {
    public:

        explicit SkprwatTable(const DeckKeyword& table);

        size_t getTableNumber() const;


    private:
        // TODO: maybe this one is not necessary
        // TODO: maybe table number should go to base class
        size_t m_table_number;
    };

}

#endif //OPM_PARSER_SKPRWAT_TABLE_HPP
