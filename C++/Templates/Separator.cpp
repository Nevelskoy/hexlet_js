//Функция раскладывает значения заданной последовательности в два пустых контейнера 
//согласно заданному условию. 

//////////(.h)//////////
template<typename Source, typename Cont_1, typename Cont_2, typename Predicat>
void Separate(const Source& s, Cont_1& c1, Cont_2& c2, Predicat pred) {
	std::copy_if(std::begin(s), std::end(s), inserter(c1, c1.end()), pred);

	std::remove_copy_if(std::begin(s), std::end(s), inserter(c2, c2.end()), pred);
}


//////////(.cpp)//////////
{
		//Разложим согласно условию: те значения, которые попадают в заданный диапазон, в один контейнер, остальные - в другой
		double ar[] = { 0.8, 1.1, 33.3, -4.1, 5.5 };
		std::set<double> s; //здесь, которые попадают в [0,4]
		std::vector<double> v; //здесь остальные
		Separate(ar, s, v, [](auto x) {
			return x > 0 && x < 4;
			});
}
