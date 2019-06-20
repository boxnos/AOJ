#include <cstdio>
#include <cctype>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define _gp(l) const auto gcu{getchar##l}; const auto pcu{putchar##l}
#ifdef __linux
_gp(_unlocked);
#else
_gp();
#endif
#define _DEF(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define _T template <typename T>
#define _HT template <typename H,typename... T>
_T _DEF(T,in,int c){T n=0;int m=1;while(isspace(c)){c=gcu();}if(c=='-')m=-1,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
_DEF(int,in,){return in<int>(gcu());}
#define _SCAN(...) _DEF(bool,scan,__VA_ARGS__)
_T _SCAN(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_DEF(bool, scan, int &c){c=gcu();gcu();return c!=EOF;}
#ifdef _GLIBCXX_STRING
_SCAN(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=(char)c;}}
#endif
_HT _SCAN(H &h,T&&... t){return scan(h)&&scan(t...);}
#define _OUT(...) _DEF(void,out,__VA_ARGS__)
#define _OUTL(...) _DEF(void,outl,__VA_ARGS__)
_OUT(bool b){pcu('0'+b);} _OUT(const char *s){while(*s)pcu(*s++);} _OUT(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_OUT(string s){for(char c:s)pcu(c);}
#endif
_T _OUT(T n){static char b[20];char *p=b;T m=n<0?pcu('-'),-1:1;
	if(!n)*p++='0';else while(n)*p++=(char)(n%10*m+'0'),n/=10;while(p!=b)pcu(*--p);}
_OUTL(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _OUT(vector<T> v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
_HT _OUT(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _OUTL(T&&... t){out(move(t)...);outl();}
struct range{
	int e,b=0,s=1; range(int _b,int _e,int _s):e(_e),b(_b),s(_s){} range(int _b,int _e): e(_e), b(_b){} range(int _e):e(_e){}
	struct it { int v, s; it (int _v, int _s) : v(_v), s(_s) {} operator int()const{return v;} operator int&(){return v;} int operator*()const{return v;}
		it& operator++(){v+=s;return *this;} }; it begin() {return {b, s};} it end() {return {e, s};}};

/*
struct sieve {
	long N {12000000L};
	vector<bool> s;
	sieve() {
		s.resize(N);
		s[2] = true;
		for (long i = 3; i < N; i += 2)
			s[i] = true;
		for (long i = 9; i < N; i += 6)
			s[i] = false;
		for (long i = 6, e = sqrt(N); i <= e; i += 6) {
			for (long j : {i - 1, i + 1})
				if (s[j])
					for (long k = j * j; k < N; k += j)
						s[k] = false;
		}
	}
};

int main() {
	sieve s;
	for (long i = 13; i < 10100000L; i += 2)
		if (s.s[i] && s.s[i - 2] && s.s[i - 6] && s.s[i - 8])
			out(i, ',');
	outl();
}
*/

int main() {
	const vector<long> p4 {13,19,109,199,829,1489,1879,2089,3259,3469,5659,9439,13009,15649,15739,16069,18049,18919,19429,21019,22279,25309,31729,34849,43789,51349,55339,62989,67219,69499,72229,77269,79699,81049,82729,88819,97849,99139,101119,109849,116539,119299,122209,135469,144169,157279,165709,166849,171169,187639,194869,195739,201499,201829,217369,225349,240049,243709,247609,247999,257869,260419,266689,268819,276049,284749,285289,294319,295879,299479,300499,301999,326149,334429,340939,346399,347989,354259,358909,361219,375259,388699,389569,392269,394819,397549,397759,402139,402769,412039,419059,420859,427249,442579,444349,452539,463459,465169,467479,470089,477019,490579,495619,500239,510619,518809,536449,536779,539509,549169,559219,563419,570049,572659,585919,594829,597679,607309,622249,626629,632089,632329,633469,633799,654169,657499,661099,663589,664669,666439,680299,681259,691729,705169,715159,734479,736369,739399,768199,773029,795799,803449,814069,822169,823729,829729,833719,837079,845989,854929,855739,857959,875269,876019,881479,889879,907399,930079,938059,946669,954979,958549,959479,976309,978079,983449,1002349,1003369,1006309,1006339,1008859,1015369,1022389,1022509,1023949,1027759,1043599,1063969,1065019,1068259,1068709,1091269,1093069,1093999,1100839,1117609,1117819,1118869,1120549,1121839,1122139,1126669,1137889,1146799,1155619,1156039,1157839,1163719,1167709,1168249,1170139,1172029,1172539,1173589,1182289,1210879,1228399,1230379,1233439,1246249,1246369,1257079,1272289,1285519,1298119,1322179,1322599,1324579,1329709,1337269,1339909,1340329,1351249,1352209,1358809,1360789,1368469,1381279,1400809,1402369,1410979,1440589,1447009,1451839,1461409,1468639,1508629,1514329,1524079,1525969,1540969,1571749,1573549,1573939,1577299,1584439,1588759,1592869,1603339,1615849,1616809,1621729,1627609,1631059,1653109,1659109,1670569,1678759,1681879,1685449,1691869,1711819,1718869,1727779,1747729,1748479,1749499,1755829,1764229,1780489,1791739,1797379,1798639,1802659,1819849,1830349,1833529,1834039,1837399,1857679,1890529,1902619,1904479,1910269,1912069,1912459,1915939,1917739,1925389,1943659,1954159,1954369,1959319,1979149,1979899,2002339,2007619,2007919,2016409,2020729,2050339,2062009,2063779,2065579,2075839,2079199,2083519,2084449,2087389,2107669,2116579,2136139,2141809,2143489,2144509,2157739,2159239,2168659,2176639,2177509,2193889,2202799,2203969,2223679,2225059,2246149,2248249,2256349,2262979,2266639,2289649,2290039,2294059,2303599,2340259,2342779,2362279,2373409,2376169,2381089,2403889,2413429,2418679,2423419,2443789,2458669,2470339,2478529,2479669,2499949,2508049,2535109,2541949,2546239,2552119,2552659,2561269,2564329,2576599,2594959,2594989,2596669,2604739,2614069,2635489,2668249,2673529,2674549,2679499,2683789,2696929,2704909,2712379,2715289,2728549,2731699,2731909,2759299,2761729,2764129,2790259,2805169,2822719,2839939,2840269,2846869,2849689,2875339,2879299,2893489,2918569,2927599,2927809,2952799,2954689,2989039,2990839,3047419,3058879,3062209,3063499,3066829,3076399,3089329,3092569,3101479,3103279,3129619,3153589,3157579,3171739,3187609,3200209,3207439,3208819,3215749,3224869,3243349,3277699,3295549,3308959,3326629,3328909,3340879,3366829,3371449,3374479,3378049,3400219,3416059,3436249,3437719,3467539,3479899,3512059,3512239,3512989,3513079,3514549,3518329,3550699,3584929,3586909,3593509,3621469,3652939,3669769,3690529,3713449,3727729,3735169,3741169,3798079,3817819,3837139,3837859,3849829,3854119,3894049,3919219,3919249,3951559,3974359,3974689,3975709,3995449,3996529,4015939,4016569,4032409,4039669,4042609,4058479,4059199,4092709,4098469,4110349,4138249,4144969,4155919,4157899,4174609,4185919,4208629,4218289,4224379,4234429,4257529,4262179,4265089,4265719,4285669,4300189,4316779,4326409,4332619,4336099,4353319,4361479,4370089,4377679,4396789,4404559,4405699,4413589,4415449,4453489,4467019,4487809,4510489,4529389,4540099,4543249,4544209,4561639,4575289,4579879,4596079,4606579,4609309,4615609,4627879,4635979,4647289,4660549,4675249,4693699,4706419,4707979,4734679,4740649,4743709,4796089,4809949,4832419,4833139,4852459,4868659,4875259,4900459,4950139,4956829,4959049,4972069,4977439,4997389,5025079,5037919,5047129,5073379,5074879,5146489,5154769,5158039,5168929,5184799,5201299,5205469,5229409,5234689,5239189,5248099,5251789,5253769,5261749,5274169,5274679,5278579,5318899,5327899,5381869,5382109,5417389,5425759,5436289,5450119,5461999,5465359,5484139,5499079,5527009,5610469,5614159,5651749,5675149,5698579,5732149,5733529,5734699,5760109,5774149,5805259,5839579,5841469,5851429,5860249,5892709,5908459,5922229,5928829,5930929,5937859,5938789,5969659,5977339,5986039,6005899,6013159,6016099,6023659,6024049,6054289,6056209,6066589,6102919,6106489,6130549,6136219,6144379,6153319,6156979,6177889,6187459,6193309,6201499,6213799,6250429,6261379,6287929,6297589,6299149,6324559,6329509,6332869,6334879,6359239,6378139,6402169,6404779,6406579,6419299,6438199,6464209,6471139,6474829,6484069,6495949,6498229,6501799,6503599,6509689,6510199,6512089,6528679,6556609,6561019,6578659,6582469,6595579,6600499,6601789,6602209,6613339,6616789,6621289,6631909,6641359,6655549,6655639,6692269,6699619,6700699,6708859,6715279,6715999,6727549,6735019,6740479,6753829,6758959,6760009,6787639,6796639,6843379,6880879,6884749,6900919,6915199,6918019,6918349,6925159,6937969,6942499,6945559,6949339,7014619,7016749,7025659,7027459,7039849,7045699,7051399,7079719,7081189,7097809,7130869,7151149,7159519,7161859,7166149,7177069,7187779,7201639,7235959,7267459,7273999,7286689,7305379,7316299,7328779,7335949,7340239,7348639,7356079,7367029,7369339,7371649,7417519,7422229,7433059,7448479,7464559,7465489,7475389,7477999,7483789,7499209,7527259,7534069,7534609,7537339,7540459,7541929,7545919,7580389,7583509,7599049,7610929,7641379,7645669,7659019,7669819,7681369,7701769,7703239,7734829,7754899,7774309,7802239,7806439,7813369,7814299,7846549,7861039,7879849,7882879,7913239,7934659,7945039,7960159,7961959,7989469,8023669,8059069,8062009,8070919,8101789,8108539,8166079,8178259,8183899,8194939,8208919,8248069,8281579,8312419,8313919,8318419,8326609,8336599,8339629,8344159,8348539,8381539,8385109,8431069,8445979,8460589,8467639,8487379,8497039,8513179,8519479,8540509,8557729,8561809,8568409,8573449,8576599,8594689,8604649,8616919,8619439,8621869,8623039,8648839,8658109,8669629,8677399,8685379,8691589,8717749,8729059,8741149,8748589,8773159,8799619,8827549,8831989,8833249,8844379,8868529,8878279,8898319,8914189,8926459,9020989,9081469,9081889,9083029,9127639,9138139,9146989,9154969,9165259,9220249,9276859,9280549,9291649,9299449,9320329,9324439,9353299,9365599,9369559,9394969,9426499,9439279,9440449,9446869,9463249,9479419,9494209,9503959,9508069,9511429,9538099,9541999,9549109,9550399,9585889,9589429,9600559,9600589,9617989,9627469,9640489,9721429,9723019,9725959,9733819,9739909,9743479,9744409,9750079,9774469,9778039,9783889,9792709,9835759,9876109,9892039,9910759,9917059,9923989,9933619,9950209,9950539,9973219,10013959};
	for (long n; (n = in());)
		outl(*(upper_bound(begin(p4), end(p4), n) - 1));
}

/* vim: set ts=4 noet: */
