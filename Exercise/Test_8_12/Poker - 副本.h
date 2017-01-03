有问题，用数组定义扑克牌无法反推play的牌面在值

/*
	poker类
		suit;		\\花色;
		block;	\\牌值
		
	洗牌
	for(i!=52){
		suit = radom*4
		face= radom*13
		if(arr[suit][block]==0)
		{
				arr[suit][block]=i;
		}
	}
	
	发牌
	
	for（i!=52）
	{
		fapai=false;
		for(x!=4)
		{
			for(y!=13)
			{
				if(1==arr[x][y])
				{
					x=x;
					y=y;
					}
					}
		}
	}
	
	play
	手牌数52/4
	string arr[手牌数] = p_Ptr
	for（i!=52）
		
			swith(i%4)
		{
			case:0
			case:1
			case:2
			case:4
		}
	
*/	