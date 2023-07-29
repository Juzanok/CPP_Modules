#!/bin/sh

make re

GREEN='\033[2;32m'
YELLOW='\033[2;33m'
RESET='\033[0m'

echo ""
echo -e "${YELLOW}[ ERROR TESTS ]${RESET}"
echo ""

echo -e "${YELLOW}./RPN \"1 1 1\"${RESET}"
./RPN "1 1 1"
echo -e "${YELLOW}./RPN \"+1 1 1\"${RESET}"
./RPN "+1 1 1"
echo -e "${YELLOW}./RPN \"1 1+ 1\"${RESET}"
./RPN "1 1+ 1"
echo -e "${YELLOW}./RPN \"1 1 1+\"${RESET}"
./RPN "1 1 1+"
echo -e "${YELLOW}./RPN \"1 + 1\"${RESET}"
./RPN "1 + 1"
echo -e "${YELLOW}./RPN \"+ 1 1\"${RESET}"
./RPN "+ 1 1"
echo -e "${YELLOW}./RPN \"1 /1 1\"${RESET}"
./RPN "1 /1 1"
echo -e "${YELLOW}./RPN \"1 / 1 1\"${RESET}"
./RPN "1 / 1 1"
echo -e "${YELLOW}./RPN \"1 + 1 1\"${RESET}"
./RPN "1 + 1 1"
echo -e "${YELLOW}./RPN \"1 1 + 1\"${RESET}"
./RPN "1 1 + 1"
echo -e "${YELLOW}./RPN \"1 1 1 1\"${RESET}"
./RPN "1 1 1 1"
echo -e "${YELLOW}./RPN \"1 1 + 1 + 1 + 1 1\"${RESET}"
./RPN "1 1 + 1 + 1 + 1 1"
echo -e "${YELLOW}./RPN \"1 1 + 1 1 + 1 + 1 +\"${RESET}"
./RPN "1 1 + 1 1 + 1 + 1 +"
echo -e "${YELLOW}./RPN \"1 . 1\"${RESET}"
./RPN "1 . 1"
echo -e "${YELLOW}./RPN \"1 1 + . +\"${RESET}"
./RPN "1 1 + . +"
echo -e "${YELLOW}./RPN \"1 1 + j +\"${RESET}"
./RPN "1 1 + j +"
echo -e "${YELLOW}./RPN \"1 1 + - +\"${RESET}"
./RPN "1 1 + - +"
echo -e "${YELLOW}./RPN \"1 1 + -\"${RESET}"
./RPN "1 1 + -"
echo -e "${YELLOW}./RPN \"    \"${RESET}"
./RPN "    "
echo ""


echo -e "${GREEN}[ SOLUTION TESTS ]${RESET}"
echo ""

echo -e "${GREEN}./RPN \" 1 2 * 2 / 5 + 4 6 * 6 / 8 * 2 / + 2 * 2 - \" => 42${RESET}"
./RPN " 1 2 * 2 / 5 + 4 6 * 6 / 8 * 2 / + 2 * 2 -"
echo ""

echo -e "${GREEN}./RPN \" 1 1 + \" => 2${RESET}"
./RPN "1 1 +"
echo ""

echo -e "${GREEN}./RPN \" 1 \" => 1${RESET}"
./RPN "1"
echo ""

echo -e "${GREEN}./RPN \" 9 9 + \" => 18${RESET}"
./RPN "9 9 +"
echo ""

echo -e "${GREEN}./RPN \" 9 9 + 9 + \" => 27${RESET}"
./RPN "9 9 + 9 +"
echo ""

echo -e "${GREEN}./RPN \" 5 5 * \" => 25${RESET}"
./RPN "5 5 *"
echo ""

echo -e "${GREEN}./RPN \" 5 5 * 5 * \" => 125${RESET}"
./RPN "5 5 * 5 *"
echo ""

echo -e "${GREEN}./RPN \" 5 5 * 5 / \" => 25${RESET}"
./RPN "5 5 * 5 /"
echo ""

echo -e "${GREEN}./RPN \" 9 9 * 7 * 5 + 2 - -8 + \" => 562${RESET}"
./RPN "9 9 * 7 * 5 + 2 - -8 +"
echo ""
