#pragma once

class UStatusUnit
{
public:
	int GetHp     () const
	{ 
		return Hp; 
	}				 
	int GetMinAtt () const
	{
		return MinAtt; 
	}
	int GetMaxAtt () const
	{
		return MaxAtt;
	}
	int GetSpeed  () const
	{
		return Speed ;
	}
	int GetGold	  () const
	{
		return Gold  ;
	}

	void SetHp    (int _Value) { Hp     = _Value;}
	void SetMinAtt(int _Value) { MinAtt = _Value;}
	void SetMaxAtt(int _Value) { MaxAtt = _Value;}
	void SetSpeed (int _Value) { Speed  = _Value;}
	void SetGold  (int _Value) { Gold   = _Value;}

protected:
	int Hp     = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed  = 10;
	int Gold   = 0;

};

