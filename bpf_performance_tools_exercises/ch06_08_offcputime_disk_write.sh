#!/bin/bash

#Reference: https://www.brendangregg.com/FlameGraphs/offcpuflamegraphs.html

git clone http://github.com/brendangregg/FlameGraph
cd FlameGraph
/usr/share/bcc/tools/offcputime -df 30 > out.stacks
./flamegraph.pl --color=io --title="Off-CPU Time Flame Graph" --countname=us < out.stacks > ch06_08_offcputime_disk_write.svg
