#ifndef Graphic
#define Graphic
#ifndef _VECTOR_
#undef _VECTOR_
#include <vector>
#define _VECTOR_
#else
#include <vector>
#define _VECTOR_
#endif


#define _INFINITY 65535  //定义无穷大

template <typename type> class Graph
{
private:
	type *  vexs; //点数组地址
	type * arcs;  //邻接矩阵的首地址
	int numVertexs, numEdges; //	图中点和边
	bool * visit;  //定义遍历标记矩阵
	bool applyVisit();
	void DFS(int i); //深度优先遍历函数
	void BFS(int i); //广度优先遍历函数
	std::vector<int> Queue;  //队列
public:
	Graph(){}
	~Graph()
	{
		if (vexs)
			delete[] vexs;
		if (arcs)
			delete[] arcs;
	}
	bool CreateGraph();//创建图
	bool CreateVectorGraph()//创建有向图
	{
		if (CreateGraph());
		else return false;
		for (int i = 0; i < numVertexs; i++)
			for (int j = i + 1; j < numVertexs; j++)
				arcs[j*numVertexs + i] = arcs[i*numVertexs + j];  //无向图，为对称矩阵
		return true;
	}
	void print();//测试
	void CalDegree();
	void DFSTraverse(); //深度优先遍历接口
	void BFSTraverse(); //广度优先遍历接口
	void Min_SpanTree_Prim();  //Prim最小生成树
};

template <class type>void Graph<type>::Min_SpanTree_Prim()
{
	std::cout << "最小生成树路径：";
	int min;
	int * used, *Edges;//used 数组保存结点下标，Edges数组保存相应接地那的权值
	if (!(used = new int[numVertexs])) 
		exit(0);
	if (!(Edges = new int[numVertexs]))
		exit(0);
	used[0] = 0; //初始化第一个顶点下表为0
	Edges[0] = 0; //初始化第一个顶点的权值为0，即第一个顶点加入生成树
	for (int i = 1; i < numVertexs; i++)
	{
		Edges[i] = arcs[i];
		used[i] = 0;
	}
	for (int j = 1; j < numVertexs; j++)  //遍历每个点
	{
		min = _INFINITY;  //将最小权值设置为无穷大
		int k = 1, m = 0;  //m用来记录当前最小权值对应的结点下标
		while (k < numVertexs) //得到某个点的边的最小权值
		{
			if (Edges[k] != 0 && Edges[k] < min)
			{
				min = Edges[k];
				m = k;
			}
			k++;
		}
		std::cout << used[m] + 1 << "-->" << m + 1 << std::endl;
		Edges[m] = 0;  //设定某个点的权值为0，表示以已经加入最小生成树
		for (int n = 1; n < numVertexs;n++)
		{
			if (Edges[n] != 0 && arcs[m*numVertexs + n] < Edges[n])
			{
				Edges[n] = arcs[m*numVertexs + n];
				used[n] = m;
			}
		}
	}
	delete[] used;
	delete[] Edges;
}


template <class type>void Graph<type>::BFS(int i)
{
	visit[i] = true;
	std::cout << vexs[i];
	int j;
	Queue.push_back(i);  //进队列
	while (!Queue.empty()) //当队列不为空
	{
		j = Queue[0];  //获得第一个元素值
		Queue.erase(Queue.begin()); //第一个元素出队
		for (int k = 0; k < numVertexs; k++)
		{
			if (arcs[i*numVertexs + k] != _INFINITY && arcs[i*numVertexs + k] != 0)
				if (!visit[k])
				{
					visit[k] = true;
					std::cout << vexs[k];
					Queue.push_back(k);
				}
		}
	}
}

template <class type>void Graph<type>::BFSTraverse()
{
	if (applyVisit())
	{
		std::cout << "广度优先遍历：" << std::endl;
		for (int i = 0; i < numVertexs; i++)
			if (!visit[i])
				BFS(i);
	}
}
template <class type>void Graph<type>::DFS(int i)
{
	visit[i] = true;
	std::cout << vexs[i];
	for (int j = 0; j < numVertexs; j++)
		if (arcs[i*numVertexs + j] != _INFINITY && arcs[i*numVertexs + j] != 0)
			if (!(visit[j]))
				DFS(j);
}


template <class type>inline void Graph<type>::DFSTraverse()
{
	if (applyVisit())
	{
		std::cout << "深度遍历:" << std::endl;
		for (int i = 0; i < numVertexs; i++)
			if (!visit[i])
				DFS(i);
	}
}

template<class type>void Graph<type>::CalDegree()
{
	int D;
	for (int i = 0; i < numVertexs; i++)
	{
		D = 0;
		for (int j = 0; j < numVertexs; j++)
		{
			if (arcs[i*numVertexs + j] != _INFINITY)
				D++;
		}
		std::cout << "第" << i + 1 << "个结点的度为：" << D << std::endl;
	}

}

template<class type>bool Graph<type>::CreateGraph()
{
	std::cout << "请分别输入图中的结点总数和边总数：";
	std::cin >> numVertexs >> numEdges;
	if (!(vexs = new type[numVertexs]))  //申请结点数组
		return false;
	if (!(arcs = new type[numVertexs*numVertexs])) //申请邻接矩阵
		return false;
	//memset(arcs, _INFINITY, numVertexs*numVertexs);  //初始化邻接矩阵
	for (int i = 0; i < numVertexs*numVertexs; i++)//这里并没有将矩阵的左上角与右下角连线上的元素初始化为0，但这并不影响程序的正确执行
		arcs[i] = _INFINITY;
	for (int i = 0; i < numVertexs; i++)  //导入图顶点数据
	{
		std::cout << "请输入第" << i + 1 << "个顶点的值：";
		std::cin >> vexs[i];
	}
	for (int i, j, w, k = 0; k < numEdges; k++)
	{
		std::cout << "请输入边的两个顶点的顺序值与此边的权值：";
		cin >> i >> j >> w;
		arcs[(i - 1)*numVertexs + j - 1] = w;
	}

	return true;
}

template <class type>void Graph<type>::print()
{
	for (int i = 0; i < numVertexs; i++)
	{
		for (int j = 0; j < numVertexs; j++)
			std::cout << arcs[i*numVertexs + j] << "  ";
		std::cout << std::endl;
	}
}

template <class type >bool Graph<type>::applyVisit()
{
	if (visit)
		delete[]visit;
	if (!(visit = new bool[numVertexs]))
		return false;
	for (int i = 0; i < numVertexs; i++)  //初始化遍历矩阵标记为0
		visit[i] = false;
	return true;
}

#endif
