#ifndef VG_TRANSLATOR_H
#define VG_TRANSLATOR_H
// translator.hpp: defines the Translator, which maps paths on an augmented graph
// into the base graph defined by a set of Translations from the augmented graph

#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <vector>
#include <list>
#include "vg.pb.h"
#include "vg.hpp"
#include "hash_map.hpp"
#include "utility.hpp"
#include "types.hpp"

namespace vg {

using namespace std;

/**
 * Class to map paths into a base graph found via a set of Translations
 */
class Translator {
public:

    vector<Translation> translations;
    map<pos_t, Translation*> pos_to_trans;
    Translator(void);
    Translator(istream& in);
    Translator(const vector<Translation>& trans);
    void load(const vector<Translation>& trans);
    void build_position_table(void);
    Translation get_translation(const Position& position);
    Position translate(const Position& position);
    Position translate(const Position& position, const Translation& translation);    
    Mapping translate(const Mapping& mapping);
    Path translate(const Path& path);
    Alignment translate(const Alignment& aln);
    Locus translate(const Locus& locus);
    Translation overlay(const Translation& trans);
};

bool is_match(const Translation& translation);

enum Fileformat : char
{
    unknown = -1,
    bam = 0,
    fq, fastq = 1,
    gam = 2,
    gfa = 3,
    json = 4,
    locus = 5,
    pileup = 6,
    stream = 7,
    translation = 8,
    turtle_in = 9,
    vg = 10
};


}

#endif
