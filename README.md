Note


Data 1.10

1. Big Three（拷贝构造，拷贝赋值，析构函数）
    当class中有指针的时候，这三个函数必须重写，不能使用默认的。
    拷贝构造
    拷贝复制：首先判断自赋值，然后1.删除 2.申请空间 3.复制
    析构函数

2. new delete malloc free
    new 的背后:  
    先分配空间，再调用ctor
        1. 调用operator new(sizeof(class_name)); 申请空间,其中operator_new中封装的就是malloc
        2. 强制类型转换 pc = static_cast<class_name>(mem);
        3. 调用ctor；

    delete 的背后：
    先调用析构函数，再删除空间(operator delete(封装了free))



3. Rvalue reference and Move Semantics
solve the problem of nunecessary copying and enable perfct forwarding(完美转交)
    1. Lvalue & Rvalue
        Lvalue can appear on the left of operator=
        Rvaue only could appear on the right of operator=
        for example：
        int a = 9, b = 4;
        a,b are Lvalue, "a+b" is a Rvalue. Temporary object often is a Rvalue in our daily code.
        To a summar, "a+b" and temporary object are two type Rvalue which we usually use in daily code.

    2. temporary object -- compiler defaults to using move sematics, but we also can use move semantics when the object is to be used once.

    3. how to steal? -- copy the ptr 

    

    
    
