# SP_LW_6

Порядок виконання:
1) Збір статистики:
  1.1) /usr/bin/time -v ./FlameGraph/lr6
  1.2) sudo sysctl kernel.perf_event_paranoid=-1
       cd FlameGraph
       perf stat -d ./lr6
  1.3) perf record -a -g ./lr6 sleep 3
       perf report
       perf script | ./stackcollapse-perf.pl > out.perf-folded
       ./flamegraph.pl out.perf-folded > perf.svg
       firefox perf.svg
2) Продемонструвати різницю в коді через godbolt.org
3) Виконати крок 1, тепер з файлом nlr6
