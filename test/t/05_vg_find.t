#!/usr/bin/env bash

BASH_TAP_ROOT=../bash-tap
. ../bash-tap/bash-tap-bootstrap

PATH=..:$PATH # for vg

plan tests 4

vg construct -r small/x.fa -v small/x.vcf.gz >x.vg
is $? 0 "construction"

vg index -s x.vg
is $? 0 "indexing nodes and edges of graph"

vg index -k 11 x.vg
is $? 0 "indexing 11mers"

# we should hit nodes 1 3 8 9 13 14
matches=$(vg find -k TAAGGTTTGAA -c 0 x.vg | vg view -g - | grep "^S" | cut -f 2 | grep '1$\|3$\|8$\|9$\|13$\|14$' | wc -l)
is $matches 6 "correct number of nodes for kmer find"

rm -rf x.vg.index
rm -f x.vg
