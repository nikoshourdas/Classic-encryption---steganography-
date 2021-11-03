
clear

gcc Cipher.cpp
gcc Cipher.cpp -o cipherexe

./cipherexe

chmod 755  CipherText.txt


line=`cat CipherText.txt`

echo $line

./c-steg --encode-lossless --input-file ./src/libjpeg/testimg.jpg --output-file ./my-photo-encoded.jpg --text $line --quality 95 --bits-to-steal 1


./c-steg --decode-lossless --input-file ./my-photo-encoded.jpg



