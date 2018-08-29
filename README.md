# 自作OS(仮称)
x86 32bit なOSです。  

## 開発環境
OS : Linux(CentOS7.1)  
使用プログラミング言語 : C, GNU Assembler  
GCC バージョン : gcc version 6.3.0  

記事毎に使用したソースコードと解説記事は[Releases](https://github.com/Shadow5523/osdev/releases)から参照することができる。  
  
## コンパイル  
※クロスコンパイラの導入方法は下記記事を参照。  
[OSを自作してみる1 ～Linuxで自作OSを作る環境を構築する～](https://zeus.shadow-net.jp/?p=118)  

1.osdevレポジトリをcloneする。  
git clone https://github.com/Shadow5523/osdev.git  
  
2.ソースコードのディレクトリへ移動  
cd osdev/src  
  
3.makeを使用してコンパイルする。同じディレクトリに出来る"myos.iso"がOSのイメージファイルとなる。  
make
  
4.make cleanでオブジェクトファイルを消すことが出来る。
make clean  

  
## コンパイル済イメージファイル
最新版のイメージファイルを以下に配置しておきます。  
   [myos.iso](/imgfile)  

  
## 参考資料
[OSDev.org](http://wiki.osdev.org/Main_Page)  
[０から作るソフトウェア開発](http://softwaretechnique.jp/OS_Development/scratchbuild.html)  
[30日でできる！　OS自作入門](https://books.google.co.jp/books/about/30%E6%97%A5%E3%81%A7%E3%81%A7%E3%81%8D%E3%82%8B_OS%E8%87%AA%E4%BD%9C%E5%85%A5%E9%96%80.html?id=ilSvAgAAQBAJ&source=kp_cover&redir_esc=y)  
[OSのようなもの](http://d.hatena.ne.jp/wocota/searchdiary?word=%2A%5B%BC%AB%BA%EEOS%5D)  
[システムコールの呼び出し方メモ](https://qiita.com/kure/items/5a1a114f9a37aeab255c)  
[x86_64環境でシステムコールを発行する](http://sugawarayusuke.hatenablog.com/entry/2016/04/22/213251)    

<center><img src="http://shadows.dip.jp/wp-content/uploads/2017/09/githubへ投稿.png" alt="" width="30%"/></center>