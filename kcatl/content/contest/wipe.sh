touch {A..M}.cpp

for file in ?.cpp ; do
    cat template.cpp > $file ;
done
