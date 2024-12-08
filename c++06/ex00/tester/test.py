import subprocess
from typing import List

# 実行コマンド
# python3 -m pytest test.py

def	diff(param: str, expected_list: List[str]):
	result = subprocess.run(['../convert', param], capture_output=True, text=True)
	
	actual_list = result.stdout.splitlines()

	# print(actual_list)
	for expected, actual in zip(expected_list, actual_list):
		assert expected == actual

# example test

def test_0():
	expected_list = ["char: Non displayable", "int: 0", "float: 0.0f", "double: 0.0"]
	diff("0", expected_list)

def	test_42f():
	expected_list = ["char: '*'", "int: 42", "float: 42.0f", "double: 42.0"]
	diff("42.0f",expected_list)

def test_nan():
	expected_list = ["char: impossible", "int: impossible", "float: nanf", "double: nan"]
	diff("nan",expected_list)

# My test
# test char
def test_a():
	expected_list = ["char: 'a'", "int: 97", "float: 97.0f", "double: 97.0"]
	diff("a",expected_list)

#test int
def test_42():
	expected_list = ["char: '*'", "int: 42", "float: 42.0f", "double: 42.0"]
	diff("42",expected_list)

def test_INT_MAX():
	expected_list = ["char: impossible", "int: 2147483647", "float: 2.14748e+09f", "double: 2.14748e+09"]
	diff("2147483647",expected_list)

def test_INT_MIN():
	expected_list = ["char: impossible", "int: -2147483648", "float: -2.14748e+09f", "double: -2.14748e+09"]
	diff("-2147483648",expected_list)

def test_31():
	expected_list = ["char: Non displayable", "int: 31", "float: 31.0f", "double: 31.0"]
	diff("31",expected_list)

# test float 
def test_0f():
	expected_list = ["char: Non displayable", "int: 0", "float: 0.0f", "double: 0.0"]
	diff("0.0f",expected_list)

def test4dot2f():
	expected_list = ["char: Non displayable", "int: 4", "float: 4.2f", "double: 4.2"]
	diff("4.2f",expected_list)

def test_n4dot2f():
	expected_list = ["char: impossible", "int: -4", "float: -4.2f", "double: -4.2"]
	diff("-4.2f",expected_list)

def test_31dot5f():
	expected_list = ["char: Non displayable", "int: 31", "float: 31.5f", "double: 31.5"]
	diff("31.5f",expected_list)

def test_inff():
	expected_list = ["char: impossible", "int: impossible", "float: inff", "double: inf"]
	diff("inff",expected_list)

def test_pinff():
	expected_list = ["char: impossible", "int: impossible", "float: +inff", "double: +inf"]
	diff("+inff",expected_list)

def test_ninff():
	expected_list = ["char: impossible", "int: impossible", "float: -inff", "double: -inf"]
	diff("-inff",expected_list)

def test_nanf():
	expected_list = ["char: impossible", "int: impossible", "float: nanf", "double: nan"]
	diff("nanf",expected_list)

def test_pnanf():
	expected_list = ["char: impossible", "int: impossible", "float: +nanf", "double: +nan"]
	diff("+nanf",expected_list)

def test_nnanf():
	expected_list = ["char: impossible", "int: impossible", "float: -nanf", "double: -nan"]
	diff("-nanf",expected_list)

def test_Over_INT_MAXf_dot():
	result = subprocess.run(['../convert', "2147483647.5f"], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 入力値が整数型(int)の範囲を超えています。"
# 	expected_list = ["char: impossible", "int: 2147483647", "float: 2.14748e+09f", "double: 2.14748e+09"]
# 	diff("2.14748e+09f",expected_list)

def test_INT_MINf():
	expected_list = ["char: impossible", "int: -2147483648", "float: -2.14748e+09f", "double: -2.14748e+09"]
	diff("-2147483648f",expected_list)

def test_Under_INT_MINf():
	result = subprocess.run(['../convert', "-2147483649f"], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 入力値が整数型(int)の範囲を超えています。"
	# expected_list = ["char: impossible", "int: -2147483648", "float: -2.14748e+09f", "double: -2.14748e+09"]
	# diff("-2147483649f",expected_list)

def test_Under_INT_MINf2():
	result = subprocess.run(['../convert', "-2147483648.5f"], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 入力値が整数型(int)の範囲を超えています。"
	# expected_list = ["char: impossible", "int: -2147483648", "float: -2.14748e+09f", "double: -2.14748e+09"]
	# diff("-2147483648.5f",expected_list)

#test double
def test_0d():
	expected_list = ["char: Non displayable", "int: 0", "float: 0.0f", "double: 0.0"]
	diff("0.0",expected_list)

def test4dot2d():
	expected_list = ["char: Non displayable", "int: 4", "float: 4.2f", "double: 4.2"]
	diff("4.2",expected_list)

def test_n4dot2d():
	expected_list = ["char: impossible", "int: -4", "float: -4.2f", "double: -4.2"]
	diff("-4.2",expected_list)

def test_31dot5d():
	expected_list = ["char: Non displayable", "int: 31", "float: 31.5f", "double: 31.5"]
	diff("31.5",expected_list)

def test_inf():
	expected_list = ["char: impossible", "int: impossible", "float: inff", "double: inf"]
	diff("inf",expected_list)

def test_pinf():
	expected_list = ["char: impossible", "int: impossible", "float: +inff", "double: +inf"]
	diff("+inf",expected_list)

def test_ninf():
	expected_list = ["char: impossible", "int: impossible", "float: -inff", "double: -inf"]
	diff("-inf",expected_list)

def test_nan():
	expected_list = ["char: impossible", "int: impossible", "float: nanf", "double: nan"]
	diff("nan",expected_list)

def test_pnan():
	expected_list = ["char: impossible", "int: impossible", "float: +nanf", "double: +nan"]
	diff("+nan",expected_list)

def test_nnan():
	expected_list = ["char: impossible", "int: impossible", "float: -nanf", "double: -nan"]
	diff("-nan",expected_list)

def test_INT_MAXd():
	expected_list = ["char: impossible", "int: 2147483647", "float: 2.14748e+09f", "double: 2.14748e+09"]
	diff("2147483647",expected_list)

def test_Over_INT_MAXd():
	result = subprocess.run(['../convert', "2147483648"], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 入力値が整数型(int)の範囲を超えています。"
	# expected_list = ["char: impossible", "int: -2147483648", "float: 2.14748e+09f", "double: 2.14748e+09"]
	# diff("2147483648",expected_list)

def test_Over_INT_MAXd_dot():
	result = subprocess.run(['../convert', "2147483647.5"], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 入力値が整数型(int)の範囲を超えています。"
	# expected_list = ["char: impossible", "int: 2147483647", "float: 2.14748e+09f", "double: 2.14748e+09"]
	# diff("2147483647.5",expected_list)

def test_INT_MINd():
	expected_list = ["char: impossible", "int: -2147483648", "float: -2.14748e+09f", "double: -2.14748e+09"]
	diff("-2147483648",expected_list)

def test_Under_INT_MINd():
	result = subprocess.run(['../convert', "-2147483649"], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 入力値が整数型(int)の範囲を超えています。"
	# expected_list = ["char: impossible", "int: -2147483648", "float: -2.14748e+09f", "double: -2.14748e+09"]
	# diff("-2147483649",expected_list)

def test_Under_INT_MINd2():
	result = subprocess.run(['../convert', "-2147483648.5"], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 入力値が整数型(int)の範囲を超えています。"
	# expected_list = ["char: impossible", "int: -2147483648", "float: -2.14748e+09f", "double: -2.14748e+09"]
	# diff("-2147483648.5",expected_list)

def test_error():
	result = subprocess.run(['../convert', "aaaaaa"], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 入力は文字(char), 整数(int), 浮動小数点(float, double)のいずれかでなければなりません。"
	# assert result.stderr.strip() == "input is invalid"

def test_error1():
	result = subprocess.run(['../convert'], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 引数の数は1つです。"
	# assert result.stderr.strip() == "arg is invalid"

def test_error2():
	result = subprocess.run(['../convert',"42","42"], capture_output=True, text=True)
	assert result.stdout.strip() == "Error: 引数の数は1つです。"
	# assert result.stderr.strip() == "arg is invalid"
