#!/bin/sh

issatisfiable ( ) {
  echo "SATISFIABLE"
  VAR=$(echo $VAR | cut -d"v" -f2- | rev | cut -d" " -f2- | rev)
  for i in $(echo $VAR)
  do
    if [ $i -gt 0 ]; then
      VAR2="$VAR2 $i"
    fi
  done

  ./satToKcolor $1 $VAR2
}

if [ $# -ne 2 ]
then
  echo "Usage :\n./getKcolor.sh [nb_colors] [graph.c]"
  exit 1
fi

if [ ! -e $2 ]
then
  echo "Second parameter is not a file."
  exit 2
fi

gcc all.h kcolorToSat.c $2 -o kcolorToSat || exit 3
gcc satToKcolor.c -lm -o satToKcolor || exit 4

VAR=$(./kcolorToSat $1 | glucose-syrup/simp/glucose -model | tail -2) 2> /dev/null
echo $VAR | grep -q "UNSATISFIABLE" && echo "UNSATISFIABLE" || issatisfiable $1
