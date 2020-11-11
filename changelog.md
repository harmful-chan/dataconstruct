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

##### 2020.11.11 15.22 pm harmful-chan
#### main.c
独立显示函数'Show()'， 用枚举类型区分不同树的类型。</br>
增加退出时释放树节点空间，树头用全局变量保存。</br>
#### bst
增加 'ReleaseBSTree()'</br>
修改 把'ShowTree()' 改为 'ShowBSTree()'</br>
修改 把节点结构体 'pare' 指针删除，改成单向树</br>
修改 把'SearchPare()' 若找不到节点则返回最后一个节点，若找到则返回它的父节点。</br>
修改 'DeleteBSTNode()'函数实现方式改进。</br>
#### avl
增加 'AdjustTree()'用于调整树平衡，会自动递归不用多次调用。</br>
增加 'ShowAVLTree()'，'ReleaseAVLTree()'，'DeleteAVLNode()' 。</br>
修改 'Traverse()'，'AdjustBalance()'，'Whirl()' 需要传入父指针。</br>
修改 把节点结构体改成单向的，删除'pare'指针。</br>
#### ds
增加 ‘DSElmNode’结构体 用于代替需要显示的树节点</br>
修改 实现方式变化，把单向树克隆成副本，再把副本转为双向树，再进行显示。</br>



