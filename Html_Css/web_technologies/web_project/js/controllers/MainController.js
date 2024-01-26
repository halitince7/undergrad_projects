app.controller('MainController', ['$scope', function($scope) 
{
  $scope.title1 = 'Portekiz Milli Takımı Hakkında Herşey'; 
  $scope.title2 = 'Öne Çıkan Haberler';
  $scope.title3 = 'Öne Çıkan Yorumlar';
  $scope.promo = 'The most popular books this month.';
  
  $scope.haberler = [
  	{ 
    	baslik: 'Portekiz\'in EURO 2016 kadrosu açıklandı', 
    	giris: 'Fransa\'nın ev sahipliğinde 10 Haziran-10 Temmuz\'da düzenlenecek 2016 Avrupa Futbol Şampiyonası\'nda (EURO 2016) mücadele edecek Portekiz Milli Takımı\'nın kadrosu açıklandı.', 
    	metin: new Date('2014', '03', '08'), 
    	cover: 'img/the-book-of-trees.jpg',
		linkk: 'haber1.html'
  	},
	
	{ 
    	baslik: 'EURO 2016\'da Portekiz penaltılarla yarı finalde', 
    	giris: 'Portekiz, normal süresi ve uzatmaları' + 
			  '1-1 biten maçta Polonya\'yı penaltılarda 5-3 mağlup ederek tur atladı.', 
    	metin: new Date('2014', '03', '08'), 
    	cover: 'img/the-book-of-trees.jpg',
		linkk: 'haber2.html'
  	},
	
	{ 
    	baslik: 'Portekiz Tarihinde ilk kez şampiyon oldu', 
    	giris: 'Portekiz, Fransa\'da düzenlenen EURO 2016 finalinde Fransa\'yı 1-0 yendi ve Avrupa şampiyonu oldu.' +
			  'Tarihinde ilk kez bu başarıya ulaşan Portekiz\'de Ronaldo gözyaşlarını tutamadı.', 
    	metin: new Date('2014', '03', '08'), 
    	cover: 'img/the-book-of-trees.jpg',
		linkk: 'haber3.html'
  	}
 ];
 
 $scope.yorumlar = [
 
  	{ 
    	baslik: 'Ramsey yoksa favori Portekiz', 
    	giris: 'Galler şu ana kadar Portekiz’in oynadığı hiçbir'
			  +'rakibe benzemiyor. Aslında Galler şampiyonadaki' 
			  +'hiçbir takıma benzemiyor demek daha doğru… Sahip oldukları ….', 
    	metin: new Date('2014', '03', '08'), 
    	cover: 'img/the-book-of-trees.jpg',
		linkk: 'yorum1.html'
  	},
	
	{ 
    	baslik: 'Avrupa\'nın kralı Portekiz', 
    	giris: '2016 Avrupa Futbol Şampiyonası\'nın finalinde Portekiz, normal süresi 0-0 biten maçta ev sahibi '
			  +'Fransa\'yı uzatmalarda 1-0 yenerek şampiyon oldu. Portekizli Pepe maçın adamı seçildi.', 
    	metin: new Date('2014', '03', '08'), 
    	cover: 'img/the-book-of-trees.jpg',
		linkk: 'yorum2.html'
  	}
 ];
  
  
  $scope.slider = [
  	{ 
    	baslik: 'The Book of Trees', 
    	giris: 19, 
    	cover: 'img/the-book-of-trees.jpg'
  	}
 ];
  
}]);