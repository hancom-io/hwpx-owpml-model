# hwpx-owpml-model



## Description
1. hwpx-owpml-model은 OOXML형태로 구성된 owpml파일 필터의 모델입니다.
2. 본 프로젝트는 한글 파일 필터중 하나인 owpml을 OOXML구조 기반으로 생성하고, 문서를 구성하는 각각의 엘리먼트들을 추출하고 저장할 수 있도록 되어있습니다.
3. OWPML모델을 이용해서 Load, Save할 수 있는 api가 제공되고 있으며 해당 api의 하위 호출 함수들을 이용해서 문서를 메모리에 올릴 수 있습니다.



## Running the tests
- 빌드 환경
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white) ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white)
- Microsoft Visual Studio 2017 15.9.42
- Microsoft Windows 10

1. OWPMLTest프로젝트내에 OWPML모델을 이용해 간단히 테스트 할 수 있는 샘플코드가 첨부되어 있습니다.
2. `VisualStudio 실행 - 솔루션 구성 선택(Debug or Release) - 솔루션 플랫폼(x86) 선택 후 빌드 시작.`
    + 빌드가 완료되면 Build/Bin 디렉토리 아래 `Owpml.lib, OWPMLApi.lib, OWPMLUtil.lib, OWPMLTest.exe` 파일이 생성됩니다.
    + `Owpml.lib, OWPMLApi.lib, OWPMLUtil.lib` 파일을 이용해서 hwpx-owpml-model 프로젝트를 활용하는 다른 프로젝트에 해당 라이브러리를 추가하여 사용할 수 있습니다. 
3. 빌드 완료 후 프로그램을 실행하려면, OWPMLTest프로젝트 속성 페이지에서 디버깅-명령 인수 탭에 **`/c 원본파일 결과파일`** 을 이용해 실행 할 수 있습니다. 
![image](https://user-images.githubusercontent.com/96164409/193709606-eb7de486-438f-40ed-9ea0-7f46a4898e31.png)


4. 커맨드 창에서 실행 할 경우, 명령프롬프트 창을 띄운 후 해당 결과물이 생성된 디렉토리로 이동, 아래 명령어를 입력하고 실행 결과를 얻을 수 있습니다.
```bash
OWPMLTest.exe /c InputFile.owpml OutputFile.owpml
```
 
## Contribution
- 소스코드 indent는 tab이 아닌 space로 사용합니다. 
- 파일 인코딩은 utf-8을 사용합니다. 
 
#### commit convention
- 제목(1 행)과 본문 사이 한 줄 띄워 분리
- 제목은 영문자 50자 이내, 작업 영역(도메인)과 작업 내용 요약 (예: "engine: xlsx 렌더링 속도 개선")
- 제목은 한글은 구문(명사형) 작성, 영어는 명령조(동사원형, 첫글자 대문자)로 작성
- 본문은 영문자 72자 줄 바꿈, what 보다는 why, how, share(정보 공유)위주로 작성

#### 클론(clone)하기

1.  로컬의 원하는 위치에서  `git clone https://github.com/hancom-io/hwpx-owpml-model.git`  명령어를 통해 프로젝트를 복사합니다.
2.  이후 각 IDE를 통해 해당 프로젝트를 오픈합니다.



#### 브랜치 만들기

1.  로컬에서 개발을 진행하기 전 main 브랜치가 아닌 곳에서 개발을 진행하기 위해(개발 도중 코드를 다시 돌려야 할 경우를 대비하여) 새로운 브랜치를 만들고 checkout합니다.  `git checkout -b [생성할 브랜치 이름]`
2.  또한 원격 저장소에 코드를 푸시할 때도 다른 브랜치를 거쳐 main 브랜치에 최종 반영하기 위해 새로운 브랜치를 만들어 푸시해줍니다.  `git push origin [생성할 브랜치 이름]`
3.  즐겁게 개발을 진행합니다.

#### 푸시(Push)하기

1.  `git status`를 사용해 커밋할 코드가 있는지 확인합니다.
2.  커밋할 코드가 있다면  `git add [디렉토리 or 파일]`  명령어를 사용하여 staging area에 변경된 코드를 올립니다.
3.  `git commit -m "#[연결할 이슈 번호]커밋 메세지"`  명령어를 통해 로컬 저장소에 코드를 커밋합니다.(이슈는 저장소 이슈 탭에서 생성 및 확인이 가능합니다.)
4.  `git push origin [main을 제외한 다른 branch]`을 통해 원격 저장소에 코드를 푸시합니다.
5.  원격 저장소 main 브랜치에 반영하기 위해  `Pull requests`를 작성합니다.
6.  코드 검사가 완료되어 main 브랜치에 반영 된다면 성공🎉

## Licences
자세한 내용은 [LICENSE.txt](https://github.com/hancom-io/hwpx-owpml-model/blob/main/LICENSE.txt) 파일을 참고하세요.

## Third_party
- Expat XML Parser - libexpat 2.0.1 // MIT License
- Expat XML Parser - libexpat 2.1.0 // MIT License
- TideSDK 1.0.0 // Apach License 2.0

## Contact
- 문의사항은 [Discussions](https://github.com/hancom-io/hwpx-owpml-model/discussions)로 자유롭게 문의 부탁합니다.
