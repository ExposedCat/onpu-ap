Hint: use https://tproger.ru/articles/awesome-bits to find out how to do something using bitwise operations.
To cut bits use formula  
`C = (N >> F) & ((1 << (L - F + 1)) -1)`, where C is result, N is given number, F and L are first and last bits inclusive respectively to cut.
