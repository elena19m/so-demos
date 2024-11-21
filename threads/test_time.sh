#!/bin/bash

NOSYNC="./thread_nosync"
M1="./thread_m1"
M2="./thread_m2"
S1="./thread_spinlock1"
S2="./thread_spinlock2"

f() {
	echo $1
	/usr/bin/time -f 'wall time: %e\ninvoluntary cs: %c \nvoluntary cs: %w' $2 1>/dev/null
	echo "-----------------"
}

f "Time & CS for no sync" $NOSYNC
f "Time & CS for mutex inside for" $M1
f "Time & CS for mutex outside for" $M2
f "Time & CS for spinlock inside for" $S1
f "Time & CS for spinlock outside for" $S2
