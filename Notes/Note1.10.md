1. Big Three（拷贝构造，拷贝赋值，析构函数）
    当class中有指针的时候，这三个函数必须重写，不能使用默认的。
    拷贝构造
    拷贝复制：首先判断自赋值，然后 1.删除 2.申请空间 3.复制
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


// 传统拷贝（C++98）
std::vector<int> v1 = {1, 2, 3, 4, 5};
std::vector<int> v2 = v1;  // 深拷贝：复制所有元素

// 移动语义（C++11）
std::vector<int> v3 = std::move(v1);  // 只转移内部指针
// v1现在为空，v3拥有v1原来的数据


    1. Lvalue & Rvalue  左值可以取地址，而右值不可以取地址

        int a = 5;           // a是左值，5是右值
        int& lref = a;       // 正确：左值引用绑定左值
        // int& rref = 5;    // 错误：左值引用不能绑定右值

        int&& rr1 = 10;      // 正确：右值引用绑定右值
        int&& rr2 = std::move(a);  // 正确：将左值转为右值引用       
        左值引用&   右值引用&&
        Lvalue can appear on the left of operator=
        Rvaue only could appear on the right of operator=
        for example：
        int a = 9, b = 4;
        a,b are Lvalue, "a+b" is a Rvalue. Temporary object often is a Rvalue in our daily code.
        To a summar, "a+b" and temporary object are two type Rvalue which we usually use in daily code.

    2. temporary object -- compiler defaults to using move sematics, but we also can use move semantics when the object is to be used once.

    3. how to steal? -- copy the ptr 
        移动构造函数，移动拷贝赋值函数 记得加关键字 noexcept
        std::move();  将里面的元素转换成强制转换成右值引用

        转发
        std::forward();//里面元素是左值，变换后还是左值；里面元素是右值，变换后还是右值
        C++中只要有名字的变量就视为左值。所以在函数中互相传递的时候，一个右值传递到func1（）中，因为有形参名字，所以在往下一个函数func2()传递时，如果不做处理就变成了左值
        正确的做法，func1（）中往func2传递的时候，fun2(std::forward(index));