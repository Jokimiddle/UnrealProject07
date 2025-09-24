# UnrealProject07
## c++ 플레이어블 폰 액터 구현
### MyGameMode: 플레이어컨트롤러와 기본 플레이어블 폰 액터를 지정하기 위해 생성
### MyPlayerController: 플레이어컨트롤러. IMC와 IA를 저장
### MyPawn: 플레이어블 폰 액터. 플레이어컨트롤러와 연결되어 
##### 구성된 컴포넌트: 캡슐, 스켈레탈메쉬, 애로우, 스프링암, 카메라로 구성
##### AddActorLocalOffset()함수로 액터 기준 이동을 구현
##### DeltaTime불러와 프레임 독립적인 이동속도 구현
##### 액터회전, 스프링암 회전으로 시점 회전을 구현

## 사용한 에셋
사용한 스켈레탈 메쉬: Game Animation Sample (https://fab.com/s/591b0a041ab5)
 