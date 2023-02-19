//program that prints every possible combination of football scoreing plays for a given score
#include <stdio.h>

int combos8(int total_score, int cur_score, int safety2, int FG3, int TD6, int TD7, int TD8){
	if ((cur_score + 8) <= total_score){
		combos8(total_score, cur_score+8, safety2, FG3, TD6, TD7, TD8+1);
	}
	if (cur_score == total_score){
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD8, TD7, TD6, FG3, safety2);
	}
	return 0;
}
int combos7(int total_score, int cur_score, int safety2, int FG3, int TD6, int TD7, int TD8){
	if ((cur_score + 7) <= total_score){
		combos7(total_score, cur_score+7, safety2, FG3, TD6, TD7+1, TD8);
	}
	if ((cur_score + 8) <= total_score){
		combos8(total_score, cur_score+8, safety2, FG3, TD6, TD7, TD8+1);
	}
	if (cur_score == total_score){
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD8, TD7, TD6, FG3, safety2);
	}
	return 0;
}
int combos6(int total_score, int cur_score, int safety2, int FG3, int TD6, int TD7, int TD8){
	if ((cur_score + 6) <= total_score){
		combos6(total_score, cur_score+6, safety2, FG3, TD6+1, TD7, TD8);
	}
	if ((cur_score + 7) <= total_score){
		combos7(total_score, cur_score+7, safety2, FG3, TD6, TD7+1, TD8);
	}
	if ((cur_score + 8) <= total_score){
		combos8(total_score, cur_score+8, safety2, FG3, TD6, TD7, TD8+1);
	}
	if (cur_score == total_score){
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD8, TD7, TD6, FG3, safety2);
	}
	return 0;
}
int combos3(int total_score, int cur_score, int safety2, int FG3, int TD6, int TD7, int TD8){
	if ((cur_score + 3) <= total_score){
		combos3(total_score, cur_score+3, safety2, FG3+1, TD6, TD7, TD8);
	}
	if ((cur_score + 6) <= total_score){
		combos6(total_score, cur_score+6, safety2, FG3, TD6+1, TD7, TD8);
	}
	if ((cur_score + 7) <= total_score){
		combos7(total_score, cur_score+7, safety2, FG3, TD6, TD7+1, TD8);
	}
	if ((cur_score + 8) <= total_score){
		combos8(total_score, cur_score+8, safety2, FG3, TD6, TD7, TD8+1);
	}
	if (cur_score == total_score){
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD8, TD7, TD6, FG3, safety2);
	}
	return 0;
}
int combos2(int total_score, int cur_score, int safety2, int FG3, int TD6, int TD7, int TD8){
	if ((cur_score + 2) <= total_score){
		combos2(total_score, cur_score+2, safety2+1, FG3, TD6, TD7, TD8);
	}
	if ((cur_score + 3) <= total_score){
		combos3(total_score, cur_score+3, safety2, FG3+1, TD6, TD7, TD8);
	}
	if ((cur_score + 6) <= total_score){
		combos6(total_score, cur_score+6, safety2, FG3, TD6+1, TD7, TD8);
	}
	if ((cur_score + 7) <= total_score){
		combos7(total_score, cur_score+7, safety2, FG3, TD6, TD7+1, TD8);
	}
	if ((cur_score + 8) <= total_score){
		combos8(total_score, cur_score+8, safety2, FG3, TD6, TD7, TD8+1);
	}
	if (cur_score == total_score){
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD8, TD7, TD6, FG3, safety2);
	}
	return 0;
}

int main(){
	int score;
	printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
	scanf("%d", &score);
	while (score > 1){
		printf("possible combinations of scoring plays: \n");
		combos2(score,0,0,0,0,0,0);
		printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
		scanf("%d", &score);
	}
	return 0;
}