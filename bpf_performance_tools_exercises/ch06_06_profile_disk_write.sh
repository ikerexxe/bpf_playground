#!/bin/bash

#Reference: https://www.brendangregg.com/FlameGraphs/cpuflamegraphs.html

git clone http://github.com/brendangregg/FlameGraph
cd FlameGraph
/usr/share/bcc/tools/profile -F 99 -adf 60 > out.profile-folded
./flamegraph.pl --colors=java out.profile-folded > ch06_06_profile_disk_write.svg
