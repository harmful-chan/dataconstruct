##### 2020.11.1 12.14am harmful-chan
#### main.c
添加 i, c, 命令</br>
```shell
# script > i 1    //插入一个元素 
# script > c     //插入写好元素
```
#### ds.c
修改里面的函数，勉强能用起来</br>

##### 2020.11.4 14.36 pm harmful-chan
#### main.c
添加 d 命令</br>
```shell
# script > i 13    //删除一个元素 
```
#### bst.c 
添加 DeleteBSTNode() 
#### bst.h
把BSTree 机构体独立出来， 用 '->head' 表示根节点
#### other
完善 ds.c 里的函数， ‘FreashTreeDS()’ 支持存入局部变量  

##### 2020年11月7日 12点44分 harmful-chan
#### main.c
把 c 命令 修改为 a 命令，支持bst，avl，两种树的显示，用 m 命令区分</br>
```shell
# script > m bst    //显示bst树
# script > m avl    //显示avl树
```
#### avl.c avl.h
基本完成 'InitAVLTree(AVLTree *)'，'InitAVLNode(AVLNode *, ElemType)'， 'InsertAVLNode(AVLTree *, AVLNode *)'
#### makefile
添加编译命令
#### 其他
添加include文件夹存放头文件


