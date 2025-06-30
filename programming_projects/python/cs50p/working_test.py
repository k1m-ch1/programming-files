from working_oneliner import convert, InvalidWorkingFormat

def assert_print_failure(function, args, expect):
	try:
		assert function(*args) == expect, (args,'->',function(*args))
	except InvalidWorkingFormat as e:
		assert e.args[0] == expect, e
	except AssertionError as e:
		print('Assertion Error:', e)

assert_print_failure(convert, ['9 am to 5 pm'], '09:00 to 17:00')
assert_print_failure(convert, ['9  am   to   5  pm'], '09:00 to 17:00')
assert_print_failure(convert, ['09  am   to   05  pm'], '09:00 to 17:00')
assert_print_failure(convert, ['12 am to 12 pm'], '00:00 to 12:00')
assert_print_failure(convert, ['9:02 Am tO 12:00 pM'], '09:02 to 12:00')
assert_print_failure(convert, ['9AmtO12pM'], '09:00 to 12:00')
assert_print_failure(convert, ['    9:02     Am   \t    tO   \n  12:00 pM    '], '09:02 to 12:00')
assert_print_failure(convert, ['9;02 AM tO 12;00 pM'], 'format of the time is wrong')
assert_print_failure(convert, ['69:69 pm to 420:420 am'], 'format of the time is wrong')
assert_print_failure(convert, ['005:00 am to 09:00 pm'], 'format of the time is wrong')
assert_print_failure(convert, ['005:00 am to 09:00 dm'], 'format of the time is wrong')
assert_print_failure(convert, ['005:00 am to 09:00 dm'], 'format of the time is wrong')
assert_print_failure(convert, ['13  am   to   14  pm'], 'format of the time is wrong')
assert_print_failure(convert, ['00  am   to   00  pm'], 'format of the time is wrong')
assert_print_failure(convert, ['9 am -> 5 pm'], "incorrect usage of 'to'")
assert_print_failure(convert, ['9 am toronto 5 pm'], "incorrect usage of 'to'")
assert_print_failure(convert, ['9 am to 12 pm then 12 pm to 5 pm'], "incorrect usage of 'to'")
assert_print_failure(convert, ['9 am to 12 pm , 12 pm to 5 pm'], "incorrect usage of 'to'")
assert_print_failure(convert, ['9 am - 12 pm , 12 pm to 5 pm'], "format of the time is wrong")
assert_print_failure(convert, ['9 am , 8am to 5 pm, 6 pm'], "format of the time is wrong")
assert_print_failure(convert, ['9 am , 8am to 5 pm, 6 pm to 1am'], "incorrect usage of 'to'")

assert_print_failure(convert, ['9 am to 5:00 pm'], "format of the time is wrong")
assert_print_failure(convert, ['10 am to 6:00 pm'], "format of the time is wrong")
assert_print_failure(convert, ['10:00 pm to 6 am'], "format of the time is wrong")
assert_print_failure(convert, ['10:00 pm to 6:00 am'], "22:00 to 06:00")









