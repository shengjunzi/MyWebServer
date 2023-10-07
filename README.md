## 技术点
### 主从Reactor多线程模式
采用主从Reactor多线程模式，以提高服务器的并发处理能力。 \
使用Round Robin算法实现负载均衡，确保请求均匀分配到各个服务器。\
利用智能指针技术，特别是使用`std::unique_ptr<>`，有效减少内存泄漏的可能，对类所拥有的资源进行安全管理。\
通过使用无锁循环队列，实现了高效的异步日志系统，提高日志记录的性能。\
采用引用传参、右值移动、完美转发等技术，减少大量拷贝操作，从而提升线程池的性能和效率。\
### 工程化
工程化方面采用以下策略：
- 使用CMake来管理项目，确保项目的可维护性和跨平台性。
- 使用`cpplint`和`clang-tidy`进行静态代码分析，保证代码质量和规范性。
- 实现了跨平台支持，特别是在MacOS和FreeBSD平台，通过自适应地编译不同的代码，确保系统的可移植性和兼容性。

### 运行
首先创建一个build文件夹，防止文件和项目混在一起,然后使用CMake生成Makefile：：
```
  mkdir build
  cd build
  cmake ..
```
生成Makefile后，使用以下命令进行代码格式化,用cpplint、clang-tidy检查代码:
```
  make format
  make cpplint
  make clang-tidy
```
将所有的警告都修改好，重新运行这三个命令直到全部通过。然后使用make指令即可编译整个网络库，会被保存到lib文件夹中，但这里没有可执行文件。如果我们需要编译可执行服务器，需要编译test目录下相应的源文件:
```
  make server
  make multiple_client
  make single_client
```
生成的可执行文件在build/test目录下，这时使用./test/server即可运行服务器。
