./pprof --dot --functions --inuse_space ./$2 ./$3  | dot -Tpng -o  $1
#./pprof --dot --functions --inuse_objects ./$2 ./$3  | dot -Tpng -o  $1
#./pprof --dot --functions --alloc_space ./$2 ./$3  | dot -Tpng -o  $1
#./pprof --dot --functions --alloc_space ./$2 ./$3  | dot -Tpng -o  $1
#./pprof --dot --functions ./$2 ./$3  | dot -Tpng -o  $1
#./pprof --dot --lines ./$2 ./$3  | dot -Tpng -o  $1
