
--#include "timetest.hpp"로 사용가능합니다.

--예시파일 main.cpp와 output.포맷을 확인해주세요

class 명은 Time이며 , 생성할떄 인자로는 샷의갯수( 그러니까 몇개의 구간에서 타임을 찍을지) 넘겨줘야합니다.
해당 클래스의 인자로 Time x(4); x.shot()을 할시 각 구간별로 타임의 스냅샷이 찍히며, 마지막으로 결과를 확인할떄,
x.print(index a, index b, format) (모두 int)를 이용해서 출력가능합니다. 예시를들면, 

int	main(void)
{
	Time x(4);

	x.shot();
	//어떤첫작업
	x.shot();
	//어떤두번쨰작업
	x.shot();
	x.print(0, 1, MS); // 구간 1-0을 MS의 하위단위별로 출력함. 각 출력인자 S,MS,NS의 결과는 output.해당포맷으로확인
	x.print_vector(iter begin, iter end, format);// 다음은 벡터의 이더레이션을이용해 다중출력을 지원하는것으로,
	원하는구간을 벡터로 만들어서 다중출력이 됩니다.
}

벡터 다중출력의 서식은 std::vector<pair<int, int> >::iterator이며 int, int에 시작 time, 끝 time을 넣어 벡터를 쌓는것으로 출력이 가능합니다.
