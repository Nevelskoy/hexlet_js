//Функция которая формирует и возвращает вектор, каждый элемент которого является суммой элементов двух 
//последовательностей разной длины и с элементами разного типа.

//////////(.h)//////////
template <typename A, typename B> 
auto SumCont(const A& a, const B& b) {
	
	size_t vecSize = std::max(std::size(a), std::size(b));

	std::vector<decltype(*std::begin(a) + *std::begin(b))> result(vecSize); // "operator+", возвращает "по значению",а (*std::begin(a)) - только по ссылке! 

	std::copy(std::begin(a), std::end(a), std::begin(result));

	std::transform(std::begin(b), std::end(b), std::begin(result), std::begin(result),
		[](const auto& var1, const auto& var2) {
		return var1 + var2;
	});
	
	return result;
}

//////////(.cpp)//////////

{
	std::vector<int> v{ 1,2,3,4 };
	std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5 };
	auto v1 = SumCont(v, l);

	std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
	double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	auto v2 = SumCont(ar, ll);

	std::set<std::string> s{ "abc", "qwerty", "my" };
	std::deque<const char*> d{ "111", "22" };
	auto v3 = SumCont(s, d);
	PrintAnyCont(v3);
}

