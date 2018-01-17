# Hackthissite.org Challenges: Realistic missions
웹해킹 관련 문제를 풀 수 있는 사이트인데 basic missions는 좀 간단한 것 같아서 실제 있을법한 문제들이 있는 [Realistic missions](https://www.hackthissite.org/missions/realistic/) 중에서 재미있어보이는 문제들을 풀어보았다. 풀이 과정을 간단하게 남겨본다. 문제 설명 과정에 힌트가 있기 때문에 메시지를 잘 읽어보는 것이 꽤 중요하다.

## Uncle Arnold's Local Band Review
```text
Your friend is being cheated out of hundreds of dollars. Help him make things even again!
```
### 문제 원본
```
From: HeavyMetalRyan 

Message: Hey man, I need a big favour from you. Remember that website I showed you once before? Uncle Arnold's Band Review Page? Well, a long time ago I made a $500 bet with a friend that my band would be at the top of the list by the end of the year. Well, as you already know, two of my band members have died in a horrendous car accident... but this ass hole still insists that the bet is on!
I know you're good with computers and stuff, so I was wondering, is there any way for you to hack this website and make my band on the top of the list? My band is Raging Inferno. Thanks a lot, man!
```

### 문제 요약
- [Uncle Arnold's Band Review Page](https://www.hackthissite.org/missions/realistic/1/)에서 본인이 속한 밴드가 연말 순위 1위를 하는지를 놓고 친구랑 500달러 내기를 했다.
- 밴드 멤버들이 교통사고로 죽었는데도 그 친구는 내기가 유효하다고한다. (공연을 할 수 없어 밴드 순위를 올릴 기회도 더이상 없다.) 
- 니가 컴퓨터를 잘 하니 웹사이트를 해킹해서 밴드를 리스트 최상단에 위치하도록 해다오.
- 밴드 이름은 **Raging Inferno**

### 문제 분석
- 점수를 1~5 사이로 선택하고 vote! 를 클릭하면 점수가 올라간다.
- 투표를 여러번 하는 것은 가능한데 이것이 반영되지는 않는다.
- 'Imposing Republic' 라는 밴드가 최상단에 있는데 평균 평점은 23.107846155906 점이다. 1~5점 사이인데 이 밴드 점수도 이상하다.
- 아무리 5점을 무한대로 눌러줘도 'Imposing Republic' 밴드의 평점을 넘어설 수는 없다. (평점이 5점이 넘으므로)

### 문제 해결

#### 소스코드보기로 확인해보니 점수를 부과하는 소스코드는 다음과 같다.
```html
		<form action="v.php" method="get">
			<input type="hidden" name="PHPSESSID" value="abcaeadfc31a5c43b2534bf995c0553f" />
			<input type="hidden" name="id" value="3" />
			<select name="vote">
				<option value="1">1</option>
				<option value="2">2</option>
				<option value="3">3</option>
				<option value="4">4</option>
				<option value="5">5</option>
			</select>
			<input type="submit" value="vote!" />
		</form>
```
#### "GET" 방식으로 form을 전송하므로 이를 변조하여 점수를 전송해본다.
```
http://www.hackthissite.org/missions/realistic/1/v.php
?PHPSESSID=abcaeadfc31a5c43b2534bf995c0553f
&id=3
&vote=10000
```
- 위 주소를 브라우저 주소창에 입력하여 점수를 한번에 10000점을 전송하여 해결!

