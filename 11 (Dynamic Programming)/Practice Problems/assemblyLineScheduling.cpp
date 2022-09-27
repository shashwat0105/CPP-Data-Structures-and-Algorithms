https://youtu.be/I9Sn1QG6jTU

CLRS

Problem Statement/Definitions
1.You own two lines of N machines each used to produce one part of a car.
2. ith Machine in line 1 is called Mi1 and ith machine in line 2 is called Mi2.
3. ith Machine in line 1 takes Ti1 time to produce part P1 whereas ith machine of line 2 takes Ti2 time.
4. It takes e1 time to put raw material into line 1 machine 1 whereas it takes e2 time to put it in line 2 machine 1.
5. It takes r1 time to get ready car from Nth machine of line 1 whereas it takes r2 time to get ready car from Nth machine of line 2.
6. To go from Mi1 to M(i+1)1 it takes 0 seconds while it takes Si2 time to go from Mi1 to M(i+1)2 

7. Si2 represents shift time to go from machine i in line1 to machine i+1 in line 2.

Si1 represents shift time to go from machine i in line2 to machine i+1 in line 1.

8. Starting from the raw material you should produce the car in minimum time possible. ith part should always be manufactured before (i+1)th part.

// Pseudo code

int go[N+1][3];
go[N][1] = t[N][1] + r1;
go[N][2] = t[N][2] + r2;

for(int machine_no = N-1; machine_no >= 1; machine_no--){
    go[machine_no][1] = t[machine_no][1] + min(go[machine_no + 1][1], shift[i][2] + go[machine_no + 1][2]);
    go[machine_no][2] = t[machine_no][2] + min(go[machine_no + 1][2], shift[i][1] + go[machine_no + 1][1]);
}
return min(e1 + go[1][1], e2 + go[1][2]);
