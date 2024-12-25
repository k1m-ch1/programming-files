import string
input_str_rev = """
M psaoic kmzmrk tpyw mrjmrmxi eyve qemr glevegxiv zmfiw gyd izivc wmrkpi wywwc feoew erh xlimv gvywxc sp kverhqe gipifvexmr qi fmvxlhec fyx xlexw wyw ej gyd izir xli sttw erh xli Fyhhle kpedivw wlsamr yt pmoi ai emr'x izir sr xli weqi xieq orsa alex m'q wecmr? Fyx jvjv xls xlmw Glvmwxqew ksrre lmx hmjjivirx rs get sr ksh (ci sr qi) ws c'epp womfmhm wmkqe ksxxe oiit xlex qiamrk wxvieo gyd M emr'x hcmr jsv cs hieheww wmrw rs qsvi.
"""
num_of_alphabet = len(string.ascii_lowercase)
key = len(input_str_rev.split()) % num_of_alphabet
l = [string.ascii_lowercase, string.ascii_uppercase]
output = ''.join([l[string.ascii_letters.index(char)//num_of_alphabet][(l[string.ascii_letters.index(char)//num_of_alphabet].index(char) - key)%num_of_alphabet]  if char in string.ascii_letters else char for char in input_str_rev])
print(output)