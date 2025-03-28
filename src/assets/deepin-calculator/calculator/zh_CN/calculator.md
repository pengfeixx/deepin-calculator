# 计算器|deepin-calculator|

## 概述

计算器是一款功能强大的桌面计算器，支持标准模式、科学模式和程序员模式。完美支持键盘输入，在键盘输入时还支持符号容错及计算结果联动。

## 模式介绍

在计算器界面，单击 ![icon_menu](../common/icon_menu.svg) > **模式**，您可以：

- 选择 **标准**，切换到标准模式界面，执行基本的加减乘除运算。
- 选择 **科学**，切换到科学模式界面，执行函数、指数、方根等高级运算。
- 选择 **程序员**，切换到程序员模式界面，执行二进制、八进制、十进制、十六进制等复杂运算。

### 标准模式

![0|standard](fig/standard_mode.png)


| 图标                       | 名称     | 说明                                                         |
| -------------------------- | :------- | ------------------------------------------------------------ |
| 0~9                        | 数字键   | 基本阿拉伯数字。                                             |
| MC                 | 清除键 | 清除所有内存。                                           |
| MR              | 存储键  | 重新调用内存。 |
| M+               | 存储键 | 内存增加；将当前数值累加到存储器中，中断数字输入。    |
| M-                | 存储键 | 内存减少；从存储器内容中减去当前显示值，中断数字输入。           |
| MS                | 存储键  | 内存存储；将输入框中的数值添加到内存列表中。                       |
| ![icon](../common/M.png)         | 存储键  | 单击![icon](../common/M.png)展开内存列表，再次单击折叠内存列表；关闭应用后内存清零。 |
| C/AC                      | 清除     | 分别表示清除当前的表达式内容；清空所有历史表达式。 |
| %                          | 百分号   | 用来输入百分号。                                             |
| ![delete](../common/delete.svg) | 删除     | 点击一次向前删除1个字符。                                    |
| +-×÷                       | 加减乘除 | 基本数学运算符，用来进行加法、减法、乘法、除法运算。         |
| .                          | 小数点   | 用来输入小数点。                                             |
| ()                         | 括号     | 用来输入括号，单击一次，同时显示左右括号。如果从键盘输入，输入左括号则出现左括号，<br>输入右括号则出现右括号，若只出现一侧括号，则表达式计算错误。 |
| =                          | 等于     | 用来得出计算结果。                                           |


### 科学模式

![0|scientific](fig/scientific_mode.png)


| 图标                       | 名称     | 说明                                                         |
| -------------------------- | :------- | ------------------------------------------------------------ |
| F-E        | 科学计数 | 单击 **F-E** 开启科学计数，再次单击关闭科学计数。 |
| ![icon](fig/MH.png)  | 存储键 | 展示内存列表及历史记录。 |
| ![icon](fig/deg.png)/![icon](fig/grad.png)/![icon](fig/rad.png) | 度量转换 | 分别计算角度、梯度、弧度。 |
| sin、cos、tan、cot          | 三角函数 | 分别计算数值的正弦、余弦、正切、余切。                        |
| sin<sup>-1</sup>、cos<sup>-1</sup>、tan<sup>-1</sup>、cot<sup>-1</sup> | 反三角函数 | 单击 **2<sup>nd</sup>** 切换到第二功能界面，分别计算sin、cos、tan、cot的反三角函数。 |
| &#124;x&#124;、Rand | F函数 | 分别计算数值的绝对值和随机显示一个31位的小数。              |
| 2<sup>nd</sup> | 第二功能键 | 单击 **2<sup>nd</sup>** 切换到第二功能界面，再次单击返回到三角函数与次方运算界面。 |
|  x<sup>2</sup>、x<sup>3</sup> 、x<sup>y</sup> | 幂函数 | 分别计算数值的平方、立方、y次方。 |
|  10<sup>x</sup>、2<sup>x</sup>、e<sup>x</sup>  | 指数函数 | 分别计算10的x次方、2的x次方和e的x次方。其中2<sup>x</sup>和e<sup>x</sup>为第二功能界面按钮。 |
|  ![icon](fig/square_root.png)、![icon](fig/cube_root.png)、![icon](fig/y_root.png) | 幂函数  | 单击 **2<sup>nd</sup>** 切换到第二功能界面，分别计算数值的平方根、立方根、x的y次方根。 |
| log、In、log<sub>y</sub><sup>x</sup> | 对数函数 | 分别以10为底的对数值、以e为底的对数值、以y为底x的对数。其中log<sub>y</sub><sup>x</sup> 为第二功能界面按钮。 |
| π | 圆周率 | 约等于3.14159......，可精确到小数点后31位。 |
| e              | 自然常数 | 约等于2.71828......，可精确到小数点后31位。 |
| Mod            | 求余函数 | 显示x/y的模数或余数。 |
| 1/x | 反比例函数 | 计算显示数值的倒数。 |
|x! | 阶乘 | 计算显示数字的阶乘。 |
|exp | 指数 | 允许输入用科学计数法表示的数字。 |



### 程序员模式

![0|scientific](fig/programmer.png)

| 图标                       | 名称     | 说明                                                         |
| -------------------------- | :------- | ------------------------------------------------------------ |
| HEX、DEC、OCT、BIN       | 进制 | 分别为十六进制、十进制、八进制、二进制；其中十进制为默认进制。 |
| ![icon](../common/back.svg) | 全键盘 | 单击返回至全键盘界面。 |
| ![icon](../common/bit.svg) | 位切换键盘 | 展示0～63位bit位，支持点击每一位bit位。 |
| QWORD/DWORD/WORD/BYTE     | 数据类型 | 单击按钮选择模式；分别为四字（64位）、双字（32位）、字（16位）、字节（8位）。 |
| ![icon](../common/arithmetic.svg)/![icon](../common/logical.svg)/![icon](../common/circular.svg)/![icon](../common/rotate.svg) | 移位切换 | 分别为算术移位、逻辑移位、循环移位、带进位循环移位。 |
| AND、OR、NOT、NAND、NOR、XOR        | 逻辑运算符 | 分别为与、或、非、与非、或非、异或。                       |
| A~F       |  字母| 仅在16进制下被激活。                 |
| <<、>>      | 移位操作符 | 分别为左移位、右移位。 |

## 功能介绍

### 千/万分位显示

计算器支持千分位和万分位数字显示。当表达式为千分位时，您可以右键单击当前表达式区域，选择 **切换为万分位**；当表达式为万分位时，右键单击当前表达式区域，选择 **切换为千分位**。



### 符号容错

计算器支持键盘操作，除了支持常规的数字和运算符，还支持数学符号容错功能，让您在键盘输入表达式时，键盘的中英文状态和大小写状态，都不会影响输入表达式。

另外还支持一些特殊的符号容错：

- 乘法符号容错处理：输入 *（星号）或x （字母x）都会触发乘法符号激活；
- 除法符号容错处理：输入 / 字符触发除法符号激活；
- 加法符号容错处理：输入 +（加号）触发加法符号激活； 
- 减法符号容错处理：输入 - （减号）或_ （下划线）都会触发减法符号激活；
- 百分号符号容错处理：输入 % 字符触发百分号激活；
- 小数点符号容错处理：输入 . （英文小数点）或。（中文句号）都会触发小数点符号激活； 
- 括号符号容错处理：输入左圆括号或右圆括号都会触发括号符号激活；
- 等于号符号容错处理：输入 **=** （等于号）或按 **Enter** 键都会触发等于号符号激活；
- 清除符号容错处理：按 **Esc** 键触发清除符号激活；
- 删除符号容错处理：按 **Backspace** 键触发删除符号激活；
- 字母符号容错处理：无论键盘上处于大写或小写状态，按下 **A~F** 键都会触发字母激活。





### 表达式

+ 在当前输入表达式区域单击 =（等号）、或按下键盘上的 **Enter** 键执行计算，当前输入框中显示计算结果数字，表达式进入历史表达式区域。
+ 重新编辑：单击某条历史表达式，可重新编辑表达式，表达式显示在输入表达式区域 ，重新编辑后按下键盘上的 **Enter** 键或 **=** （等号），修改历史表达式及联动表达式的数字结果。
+ 表达式错误：如输入的表达式错误，则无法计算结果，显示表达式错误。



### 科学计数法

在标准模式和科学模式下，计算结果分别大于16位和32位时用科学计数法显示，即计算结果取前 16 位/ 32 位乘以 10 的正负 n 次方。

+ 当计算结果为整数且大于 16 位/ 32 位时，显示数字+小数点后 15 位/ 31 位 + E + 数字。
+ 当计算结果为小数且大于 16 位/ 32 位时，显示数字+小数点后 15 位/ 31 位 + E - 数字。

![0|scientific_notation](fig/scientific_notation.png)



### 数字联动

- 当一个计算表达式显示数字结果后，可以继续输入操作符号，此时，新表达式的第一个数就是上一个表达式的计算结果。

  例如：当前表达式是 10 + 20 = 30， 显示计算结果 30 后，键入 + 号，再输入数字 9，会新建一个新的表达式为 30 + 9，按 **Enter** 键，得出新表达式的计算结果为39。

- 两个表达式产生联动后，修改上一个表达式的数字和操作符，如果其计算结果改变，则会影响与其联动的新表达式的结果。

  例如：两个表达式 10 + 20 = 30 和 30 + 9 = 39 产生联动，如果将第一个表达式的操作符 + 号修改为 x 号，算式为 10 x 20 = 200 ， 则第二个表达式自动转变为 200 + 9 = 209；根据此规则，最多可支持 9 条表达式联动。

- 重新编辑含有联动数字的表达式时，修改联动数字或联动数字的表达式错误时，联动解除，同时会取消数字高亮显示。

>![icon](../common/notes.svg)说明：仅在标准模式下支持数字联动。


## 主菜单

在主菜单中，您可以切换运算模式、切换窗口主题、查看帮助手册，了解计算器的更多信息。


### 主题

窗口主题包含浅色主题、深色主题和系统主题。

1. 在计算器界面，单击 ![icon_menu](../common/icon_menu.svg)。
2. 选择 **主题**，选择一个主题颜色。

### 帮助

查看帮助手册，进一步了解和使用计算器。

1. 在计算器界面，单击 ![icon_menu](../common/icon_menu.svg)。
2. 选择 **帮助**。
3. 查看计算器的帮助手册。


### 关于

1. 在计算器界面，单击 ![icon_menu](../common/icon_menu.svg)。
2. 选择 **关于**。
3. 查看计算器的版本和介绍。


### 退出

1. 在计算器界面，单击 ![icon_menu](../common/icon_menu.svg)。
2. 选择 **退出**。

