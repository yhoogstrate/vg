
all: map_flat.svg map_spliced.svg

gene_ref.vg: gene_ref.fa
	vg construct -r gene_ref.fa > gene_ref.vg
gene_ref.vg.xg gene_ref.vg.gcsa: gene_ref.vg
	vg index -k 11 -x gene_ref.vg.xg -g gene_ref.vg.gcsa gene_ref.vg
map.gam: gene_ref.vg.gcsa align_me.fastq
	vg map -D -x gene_ref.vg.xg -g gene_ref.vg.gcsa -f align_me.fastq > map.gam
map_flat.svg: map.gam gene_ref.vg
	vg view -d gene_ref.vg -A map.gam | dot -Tsvg -o map_flat.svg


gene_ref.annotated.vg: gene_ref.vg
	vg add --vcf benedict.vcf gene_ref.vg > gene_ref.annotated.vg
gene_ref.annotated.svg: gene_ref.annotated.vg
	vg view -d -n -p gene_ref.annotated.vg | dot -Tsvg > gene_ref.annotated.svg
gene_ref.annotated.vg.xg gene_ref.annotated.vg.gcsa: gene_ref.annotated.vg
	vg index -k 11 -x gene_ref.annotated.vg.xg -g gene_ref.annotated.vg.gcsa gene_ref.annotated.vg
map_spliced.gam: gene_ref.annotated.vg.gcsa align_me.fastq
	vg map -D -x gene_ref.annotated.vg.xg -g gene_ref.annotated.vg.gcsa -f align_me.fastq > map_spliced.gam
map_spliced.svg: map_spliced.gam
	vg view -d gene_ref.annotated.vg -A map_spliced.gam | dot -Tsvg -o map_spliced.svg



clean:
	rm -f *.fai *.vg *.xg *.gcsa *.lcp *.gam *.svg
