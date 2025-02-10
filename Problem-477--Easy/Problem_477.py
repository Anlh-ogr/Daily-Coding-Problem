functions = []
for idx in range(10):
    functions.append(lambda idx=idx: idx) # use idx as default argument
    
for jdx in functions :
    print(jdx())