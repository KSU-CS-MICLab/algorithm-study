# 코드 리뷰 과정

1. 프로젝트를 자신의 계정으로 fork 한다.
![codereview 1_1](codereview_1_1.png)
<hr/>
![codereview 1_2](codereview_1_2.png)
<hr/>
![codereview 1_2](codereview_1_2.png)

2. fork한 프로젝트를 local(자신의 컴퓨터)로 clone을 한 후 디렉토리로 이동한다. 
```
git clone https://github.com/{본인_아이디}/{저장소_아이디}
ex) git clone https://github.com/seunguklee/algorithm-study
```
```
cd {저장소_아이디}
ex) cd algorithm-study
```
![codereview 2](codereview_2.png)

3. 문제를 풀고 add / commit 한다.
```
git add 파일명
git commit -m "message"

ex) git add .  ( .(dot)을 사용하면 변화가 있는 모든 파일을 반영한다.)
    git commit -m "seunguk solve baekjoon_1000 and add 1000.cpp file"
```
![codereview 3](codereview_3.png)

4. 자신의 원격 저장소에 push 한다.
```
git push origin 브랜치이름
ex) git push origin master
```
![codereview 4](codereview_4.png)

5. PR(pull request)를 보낸다.
> 피드백을 받으면 코드를 수정한 후 add, commit, push 작업 반복.
![codereview 5_1](codereview_5_1.png)
![codereview 5_2](codereview_5_2.png)

6. 리뷰어는 피드백을 마무리하고 KSU-CS-MICLab/algorithm-study 저장소에 merge한다. **(Owner인 사람만 해당)**
![codereview 6](codereview_6.png)

7. KSU-CS-MICLab/algorithm-study 저장소와 동기화하기 위해 저장소 추가 **(최소 1번만 실행)**
```
git remote add {저장소_별칭} {base_저장소_url}
ex) git remote add upstream https://github.com/KSU-CS-MICLab/algorithm-study.git
// 위와 같이 upstream으로 저장소를 추가한 후 전체 remote 저장소 목록을 본다.
git remote -v
```

8. KSU-CS-MICLab/algorithm-study 저장소에서 브랜치를 들고온다.
```
git fetch upstream {브랜치_이름}
ex) git fetch upstream master
```
![codereview 8](codereview_8.png)

9. KSU-CS-MICLab/algorithm-study 저장소와 동기화하기.
```
git rebase upstream/{브랜치_이름}
ex) git rebase upstream/master
```
![codereview 9](codereview_9.png)

10. 3단계 부터 다시 진행하여 반복하면 된다.
