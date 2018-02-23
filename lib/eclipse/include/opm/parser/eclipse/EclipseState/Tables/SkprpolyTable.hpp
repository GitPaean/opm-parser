//
// Created by paean on 23.02.18.
//

#ifndef OPM_PARSER_SKPRPOLY_TABLE_HPP
#define OPM_PARSER_SKPRPOLY_TABLE_HPP

#include <opm/parser/eclipse/EclipseState/Tables/Simple2DTable.hpp>
namespace Opm {

    class DeckKeyword;

    class SkprpolyTable : public Simple2DTable {
    public:

        explicit SkprpolyTable(const DeckKeyword& table);

        size_t getTableNumber() const;


    private:
        double m_reference_concentration;

        // TODO: maybe this one is not necessary
        // TODO: maybe table number should go to base class
        size_t m_table_number;
    };

}

#endif //OPM_PARSER_SKPRPOLY_TABLE_HPP
