clear
make -C ../../libft
rm -rf virtual_machine
gcc -o virtual_machine *.c operations/*.c ../../libft/libft.a -I ../includes/ -I ../../libft/includes