# Branch_Prediction

## 提供快捷运行测试方式

```shell
#under ./sample_makefile目录下
make # 编译生成可执行文件
make run # 执行给出的8种输入，必须先进行make命令
make test # 对输出与标准文件进行比对
make clean # 删除 .o与可执行文件
```
## 手动执行 
默认输入格式为 

```shell
# under sample_makefile 目录下
./sim bimodal <M2> <tracefile>
./sim gshare <M1> <N> <tracefile>
```
