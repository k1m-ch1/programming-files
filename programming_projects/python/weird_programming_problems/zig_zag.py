
def create_zig_zag(target_str, row_nums):
	ret_list = [[] for _ in range(row_nums)]
	index_to_append = list(range(row_nums)) + list(range(row_nums - 2, 0, -1))
	index_to_append_len = len(index_to_append)
	print(index_to_append)
	for i, c in enumerate(target_str):
		ret_list[index_to_append[i%index_to_append_len]].append(c)

	return ret_list

print(create_zig_zag("HEYHEYHEYMONIKA", 3))
