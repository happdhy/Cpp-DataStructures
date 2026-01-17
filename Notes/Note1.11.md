1. 智能指针

    (1) std::unique_ptr
    
    特点：
    独占特权性：删除了拷贝构造和拷贝赋值，仅支持移动语义
    声明周期： 离开作用域，自动delete管理的对象

    std::unique_ptr<int> p1 = std::make_unique<int>(10);  // std::make_unique<>()  是C++14新增，搭配unique_ptr使用，功能类似new但是返回的是独占指针类型
    // std::unique_ptr<int> p2 = p1; // ❌ 编译错误，禁止拷贝
    std::unique_ptr<int> p2 = std::move(p1); // ✅ 移动：p1 变空，p2 接管

    (2) std::shared_ptr
    内部实际有两个指针，一个是数据指针，另个控制块指针，控制块中存放着计数器，自定义deleter等。
    
    std::shared_ptr<int> p1 = std::make_shared<int>(2);
    //make_shared 和 shared_ptr搭配，make_shared的好处相比于new，编译器之间给分配一整块内存存放数据和控制块


    (3) std::weak_ptr
    Todo
