按照官方题解的前提

res(c) : C次最佳操作的前缀和(最小)

很明显res(c) 是c的减函数，且按照题解的说法是凹（中国这边概念的凹，国外的convex）的

那么有a->c越大res(c)越小

此时引出参数cost 即每一次操作的成本来优化这个dp, f(c, cost) = res(c) + c*cost;

这个函数的凹凸性是不变的，因为二次求导 c*cost就没有了

 这也是个凹减c的函数，但是在保证f(c, cost)最小的情况时，c 和 cost是成反比的，

b->那么有cost越小c 越大 

整理一下a, b得到的结论

(1)使c在小于等于k的情况下尽量接近k res(c)

(2)cost与c成反比

那么可以二分cost 使c在小于等于k的情况下尽量大 从此时得到的f(c, cost)最小，res(c) = f(c, cost) - cost*c最小

