---
title: LaTex笔记(不定期更新)
date: 2018-02-06 14:46:11
tags:
- LaTex
- 笔记
---

# Latex 笔记（不定期更新）

## 标题，章和节
| 命令  | 效果 | 命令 | 效果 |
| ---- |------|-----|-----|
| \title| 标题 | \author | 作者 |
| \date |   日期   | \maketitle | 生成标题  |
| \section |  节标题 | \subsection |  小节标题 |
| \subsubsection | 次小节标题 | \paragraph | 段标题  |
| \subparagraph |  小段标题 | \part |  部分标题 |
| \appendix |  附录标题 |  \tableofcontents | 生成目录|
| \listoffigures | 插图目录| \listoftables| 表格目录|

 <!-- more -->
 
## 插入项目符号和编号
### 不带序号
关于{itemize}里序号的形式：latex默认生成的简单列表，默认为一个小圆点，而我们在写文章时可能想要一些不一样的列表符号，比如 -， * 之类的. 我们可以这样写

 ```
 \begin{itemize} 
 \item[-] something
 \item[-] something
 \end{itemize}
 ```
 
### 带序号 
 关于{enumerate}，这是用于带序号的列表。 默认生成 1，2，3。如果想要其他修饰，如(1) (2)....或step-1，step2，需要加载 \usepackage{enumerate}，然后如下使用
 
 ```
 \begin{enumerate}[step 1]
 \item something
 \item something
 \end{enumerate}
 ```
 
## 引入参考文献
```
\begin{thebibliography}{99}
\bibitem{a} something
\bibitem{b} something
\end{thebibliography}
```
 