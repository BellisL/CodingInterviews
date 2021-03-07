#include <stack>

template<typename Type>
class CS
{
public:
	CS() = default;
	~CS() = default;

	void push(const Type& vValue);
	void pop();
	Type min();

private:
	std::stack<Type> m_DataStack;
	std::stack<Type> m_MinStack;
};

int main()
{
	CS<int> MinStack;
	MinStack.push(3);
	_ASSERTE(3 == MinStack.min());
	MinStack.push(4);
	_ASSERTE(3 == MinStack.min());
	MinStack.push(2);
	_ASSERTE(2 == MinStack.min());
	MinStack.push(1);
	_ASSERTE(1 == MinStack.min());
	MinStack.pop();
	_ASSERTE(2 == MinStack.min());
	MinStack.pop();
	_ASSERTE(3 == MinStack.min());
	MinStack.push(0);
	_ASSERTE(0 == MinStack.min());

	return 0;
}

template<typename Type>
void CS<Type>::push(const Type & vValue)
{
	m_DataStack.push(vValue);

	if (m_MinStack.empty() || vValue < m_MinStack.top())
		m_MinStack.push(vValue);
	else
		m_MinStack.push(m_MinStack.top());
}

template<typename Type>
void CS<Type>::pop()
{
	_ASSERTE(!m_DataStack.empty() && !m_MinStack.empty());

	m_DataStack.pop();
	m_MinStack.pop();
}

template<typename Type>
Type CS<Type>::min()
{
	_ASSERTE(!m_DataStack.empty() && !m_MinStack.empty());

	return m_MinStack.top();
}
