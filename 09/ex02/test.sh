#!/bin/sh

make re

GREEN='\033[2;32m'
YELLOW='\033[2;33m'
RESET='\033[0m'

echo ""
echo -e "${YELLOW}[ ERROR TESTS ]${RESET}"
echo ""

echo -e "${YELLOW}[ Negative numbers TEST ] : ./PmergeMe 32 32 43 432 -234 32 3 -23${RESET}"
./PmergeMe 32 32 43 432 -234 32 3 -23
echo ""

echo -e "${YELLOW}[ Invalid number value TEST ] : ./PmergeMe 32 b2 43 432 -2a4 32 3 -23y${RESET}"
./PmergeMe 32 b2 43 432 -2a4 32 3 -23y
echo ""

echo -e "${YELLOW}[ Numbers over max value TEST ] : ./PmergeMe 32 32 43 432 234 32 3 23 2147483647 2147483648${RESET}"
./PmergeMe 32 32 43 432 234 32 3 23 2147483647 2147483648
echo ""



echo -e "${GREEN}[ SORTING TESTS ]${RESET}"
echo ""
echo -e "${GREEN}[ Numbers at max value TEST ] : ./PmergeMe 32 32 43 432 234 32 3 23 2147483647 2147483646 2147483647${RESET}"
./PmergeMe 32 32 43 432 234 32 3 23 2147483647 2147483646 2147483647
echo ""

echo -e "${GREEN}[ 50 nubers TEST ] : ./PmergeMe `jot -r 50 1 1000 | tr '\n' ' '`${RESET}"
./PmergeMe `jot -r 50 1 1000 | tr '\n' ' '`
# [ FOR LINUX ] ./PmergeMe `shuf -i 1-1000 -n 50 | tr "\n" " "`
echo ""

