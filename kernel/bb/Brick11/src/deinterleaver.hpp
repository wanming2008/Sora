#pragma once

#include "tpltrick.h"
#include "ieee80211a_cmn.h"
#include "ieee80211facade.hpp"

DEFINE_LOCAL_CONTEXT(T11aDeinterleaveBPSK, CF_VOID);
template<TFILTER_ARGS>
class T11aDeinterleaveBPSK : public TFilter<TFILTER_PARAMS>
{
public:
    DEFINE_IPORT(uchar, 48);
    DEFINE_OPORT(uchar, 48); // each bit is one 8-bit soft-value

public:
    REFERENCE_LOCAL_CONTEXT(T11aDeinterleaveBPSK);

    STD_TFILTER_CONSTRUCTOR(T11aDeinterleaveBPSK)
    { }

	FINL void deinterleaver ( const uchar * pbInput, uchar* pbOutput ) {
		pbOutput[0] = pbInput[0];
		pbOutput[1] = pbInput[3];
		pbOutput[2] = pbInput[6];
		pbOutput[3] = pbInput[9];
		pbOutput[4] = pbInput[12];
		pbOutput[5] = pbInput[15];
		pbOutput[6] = pbInput[18];
		pbOutput[7] = pbInput[21];
		pbOutput[8] = pbInput[24];
		pbOutput[9] = pbInput[27];
		pbOutput[10] = pbInput[30];
		pbOutput[11] = pbInput[33];
		pbOutput[12] = pbInput[36];
		pbOutput[13] = pbInput[39];
		pbOutput[14] = pbInput[42];
		pbOutput[15] = pbInput[45];
		pbOutput[16] = pbInput[1];
		pbOutput[17] = pbInput[4];
		pbOutput[18] = pbInput[7];
		pbOutput[19] = pbInput[10];
		pbOutput[20] = pbInput[13];
		pbOutput[21] = pbInput[16];
		pbOutput[22] = pbInput[19];
		pbOutput[23] = pbInput[22];
		pbOutput[24] = pbInput[25];
		pbOutput[25] = pbInput[28];
		pbOutput[26] = pbInput[31];
		pbOutput[27] = pbInput[34];
		pbOutput[28] = pbInput[37];
		pbOutput[29] = pbInput[40];
		pbOutput[30] = pbInput[43];
		pbOutput[31] = pbInput[46];
		pbOutput[32] = pbInput[2];
		pbOutput[33] = pbInput[5];
		pbOutput[34] = pbInput[8];
		pbOutput[35] = pbInput[11];
		pbOutput[36] = pbInput[14];
		pbOutput[37] = pbInput[17];
		pbOutput[38] = pbInput[20];
		pbOutput[39] = pbInput[23];
		pbOutput[40] = pbInput[26];
		pbOutput[41] = pbInput[29];
		pbOutput[42] = pbInput[32];
		pbOutput[43] = pbInput[35];
		pbOutput[44] = pbInput[38];
		pbOutput[45] = pbInput[41];
		pbOutput[46] = pbInput[44];
		pbOutput[47] = pbInput[47];
	}
	
    BOOL_FUNC_PROCESS(ipin)
    {
        while (ipin.check_read())
        {
            const uchar*  input = ipin.peek();
            uchar*  output = opin().append();

			deinterleaver ( input, output );

            ipin.pop();
			Next()->Process(opin());
        }
        return true;
    }
};

DEFINE_LOCAL_CONTEXT(T11aDeinterleaveQPSK, CF_VOID);
template<TFILTER_ARGS>
class T11aDeinterleaveQPSK : public TFilter<TFILTER_PARAMS>
{
public:
    DEFINE_IPORT(uchar, 96);
    DEFINE_OPORT(uchar, 96); // each bit is one 8-bit soft-value

public:
    REFERENCE_LOCAL_CONTEXT(T11aDeinterleaveQPSK);

    STD_TFILTER_CONSTRUCTOR(T11aDeinterleaveQPSK)
    { }

	FINL void deinterleaver ( const uchar * pbInput, uchar* pbOutput ) {
        pbOutput[0] = pbInput[0];
        pbOutput[1] = pbInput[6];
        pbOutput[2] = pbInput[12];
        pbOutput[3] = pbInput[18];
        pbOutput[4] = pbInput[24];
        pbOutput[5] = pbInput[30];
        pbOutput[6] = pbInput[36];
        pbOutput[7] = pbInput[42];
        pbOutput[8] = pbInput[48];
        pbOutput[9] = pbInput[54];
        pbOutput[10] = pbInput[60];
        pbOutput[11] = pbInput[66];
        pbOutput[12] = pbInput[72];
        pbOutput[13] = pbInput[78];
        pbOutput[14] = pbInput[84];
        pbOutput[15] = pbInput[90];
        pbOutput[16] = pbInput[1];
        pbOutput[17] = pbInput[7];
        pbOutput[18] = pbInput[13];
        pbOutput[19] = pbInput[19];
        pbOutput[20] = pbInput[25];
        pbOutput[21] = pbInput[31];
        pbOutput[22] = pbInput[37];
        pbOutput[23] = pbInput[43];
        pbOutput[24] = pbInput[49];
        pbOutput[25] = pbInput[55];
        pbOutput[26] = pbInput[61];
        pbOutput[27] = pbInput[67];
        pbOutput[28] = pbInput[73];
        pbOutput[29] = pbInput[79];
        pbOutput[30] = pbInput[85];
        pbOutput[31] = pbInput[91];
        pbOutput[32] = pbInput[2];
        pbOutput[33] = pbInput[8];
        pbOutput[34] = pbInput[14];
        pbOutput[35] = pbInput[20];
        pbOutput[36] = pbInput[26];
        pbOutput[37] = pbInput[32];
        pbOutput[38] = pbInput[38];
        pbOutput[39] = pbInput[44];
        pbOutput[40] = pbInput[50];
        pbOutput[41] = pbInput[56];
        pbOutput[42] = pbInput[62];
        pbOutput[43] = pbInput[68];
        pbOutput[44] = pbInput[74];
        pbOutput[45] = pbInput[80];
        pbOutput[46] = pbInput[86];
        pbOutput[47] = pbInput[92];
        pbOutput[48] = pbInput[3];
        pbOutput[49] = pbInput[9];
        pbOutput[50] = pbInput[15];
        pbOutput[51] = pbInput[21];
        pbOutput[52] = pbInput[27];
        pbOutput[53] = pbInput[33];
        pbOutput[54] = pbInput[39];
        pbOutput[55] = pbInput[45];
        pbOutput[56] = pbInput[51];
        pbOutput[57] = pbInput[57];
        pbOutput[58] = pbInput[63];
        pbOutput[59] = pbInput[69];
        pbOutput[60] = pbInput[75];
        pbOutput[61] = pbInput[81];
        pbOutput[62] = pbInput[87];
        pbOutput[63] = pbInput[93];
        pbOutput[64] = pbInput[4];
        pbOutput[65] = pbInput[10];
        pbOutput[66] = pbInput[16];
        pbOutput[67] = pbInput[22];
        pbOutput[68] = pbInput[28];
        pbOutput[69] = pbInput[34];
        pbOutput[70] = pbInput[40];
        pbOutput[71] = pbInput[46];
        pbOutput[72] = pbInput[52];
        pbOutput[73] = pbInput[58];
        pbOutput[74] = pbInput[64];
        pbOutput[75] = pbInput[70];
        pbOutput[76] = pbInput[76];
        pbOutput[77] = pbInput[82];
        pbOutput[78] = pbInput[88];
        pbOutput[79] = pbInput[94];
        pbOutput[80] = pbInput[5];
        pbOutput[81] = pbInput[11];
        pbOutput[82] = pbInput[17];
        pbOutput[83] = pbInput[23];
        pbOutput[84] = pbInput[29];
        pbOutput[85] = pbInput[35];
        pbOutput[86] = pbInput[41];
        pbOutput[87] = pbInput[47];
        pbOutput[88] = pbInput[53];
        pbOutput[89] = pbInput[59];
        pbOutput[90] = pbInput[65];
        pbOutput[91] = pbInput[71];
        pbOutput[92] = pbInput[77];
        pbOutput[93] = pbInput[83];
        pbOutput[94] = pbInput[89];
        pbOutput[95] = pbInput[95];
	}
	
    BOOL_FUNC_PROCESS(ipin)
    {
        while (ipin.check_read())
        {
            const uchar*  input = ipin.peek();
            uchar*  output = opin().append();

			deinterleaver ( input, output );

            ipin.pop();
			Next()->Process(opin());
        }
        return true;
    }
};

DEFINE_LOCAL_CONTEXT(T11aDeinterleaveQAM16, CF_VOID);
template<TFILTER_ARGS>
class T11aDeinterleaveQAM16 : public TFilter<TFILTER_PARAMS>
{
public:
    DEFINE_IPORT(uchar, 192);
    DEFINE_OPORT(uchar, 192); // each bit is one 8-bit soft-value

public:
    REFERENCE_LOCAL_CONTEXT(T11aDeinterleaveQAM16);

    STD_TFILTER_CONSTRUCTOR(T11aDeinterleaveQAM16)
    { }

	FINL void deinterleaver ( const uchar * pbInput, uchar* pbOutput ) {
        pbOutput[0] = pbInput[0];
        pbOutput[1] = pbInput[13];
        pbOutput[2] = pbInput[24];
        pbOutput[3] = pbInput[37];
        pbOutput[4] = pbInput[48];
        pbOutput[5] = pbInput[61];
        pbOutput[6] = pbInput[72];
        pbOutput[7] = pbInput[85];
        pbOutput[8] = pbInput[96];
        pbOutput[9] = pbInput[109];
        pbOutput[10] = pbInput[120];
        pbOutput[11] = pbInput[133];
        pbOutput[12] = pbInput[144];
        pbOutput[13] = pbInput[157];
        pbOutput[14] = pbInput[168];
        pbOutput[15] = pbInput[181];
        pbOutput[16] = pbInput[1];
        pbOutput[17] = pbInput[12];
        pbOutput[18] = pbInput[25];
        pbOutput[19] = pbInput[36];
        pbOutput[20] = pbInput[49];
        pbOutput[21] = pbInput[60];
        pbOutput[22] = pbInput[73];
        pbOutput[23] = pbInput[84];
        pbOutput[24] = pbInput[97];
        pbOutput[25] = pbInput[108];
        pbOutput[26] = pbInput[121];
        pbOutput[27] = pbInput[132];
        pbOutput[28] = pbInput[145];
        pbOutput[29] = pbInput[156];
        pbOutput[30] = pbInput[169];
        pbOutput[31] = pbInput[180];
        pbOutput[32] = pbInput[2];
        pbOutput[33] = pbInput[15];
        pbOutput[34] = pbInput[26];
        pbOutput[35] = pbInput[39];
        pbOutput[36] = pbInput[50];
        pbOutput[37] = pbInput[63];
        pbOutput[38] = pbInput[74];
        pbOutput[39] = pbInput[87];
        pbOutput[40] = pbInput[98];
        pbOutput[41] = pbInput[111];
        pbOutput[42] = pbInput[122];
        pbOutput[43] = pbInput[135];
        pbOutput[44] = pbInput[146];
        pbOutput[45] = pbInput[159];
        pbOutput[46] = pbInput[170];
        pbOutput[47] = pbInput[183];
        pbOutput[48] = pbInput[3];
        pbOutput[49] = pbInput[14];
        pbOutput[50] = pbInput[27];
        pbOutput[51] = pbInput[38];
        pbOutput[52] = pbInput[51];
        pbOutput[53] = pbInput[62];
        pbOutput[54] = pbInput[75];
        pbOutput[55] = pbInput[86];
        pbOutput[56] = pbInput[99];
        pbOutput[57] = pbInput[110];
        pbOutput[58] = pbInput[123];
        pbOutput[59] = pbInput[134];
        pbOutput[60] = pbInput[147];
        pbOutput[61] = pbInput[158];
        pbOutput[62] = pbInput[171];
        pbOutput[63] = pbInput[182];
        pbOutput[64] = pbInput[4];
        pbOutput[65] = pbInput[17];
        pbOutput[66] = pbInput[28];
        pbOutput[67] = pbInput[41];
        pbOutput[68] = pbInput[52];
        pbOutput[69] = pbInput[65];
        pbOutput[70] = pbInput[76];
        pbOutput[71] = pbInput[89];
        pbOutput[72] = pbInput[100];
        pbOutput[73] = pbInput[113];
        pbOutput[74] = pbInput[124];
        pbOutput[75] = pbInput[137];
        pbOutput[76] = pbInput[148];
        pbOutput[77] = pbInput[161];
        pbOutput[78] = pbInput[172];
        pbOutput[79] = pbInput[185];
        pbOutput[80] = pbInput[5];
        pbOutput[81] = pbInput[16];
        pbOutput[82] = pbInput[29];
        pbOutput[83] = pbInput[40];
        pbOutput[84] = pbInput[53];
        pbOutput[85] = pbInput[64];
        pbOutput[86] = pbInput[77];
        pbOutput[87] = pbInput[88];
        pbOutput[88] = pbInput[101];
        pbOutput[89] = pbInput[112];
        pbOutput[90] = pbInput[125];
        pbOutput[91] = pbInput[136];
        pbOutput[92] = pbInput[149];
        pbOutput[93] = pbInput[160];
        pbOutput[94] = pbInput[173];
        pbOutput[95] = pbInput[184];
        pbOutput[96] = pbInput[6];
        pbOutput[97] = pbInput[19];
        pbOutput[98] = pbInput[30];
        pbOutput[99] = pbInput[43];
        pbOutput[100] = pbInput[54];
        pbOutput[101] = pbInput[67];
        pbOutput[102] = pbInput[78];
        pbOutput[103] = pbInput[91];
        pbOutput[104] = pbInput[102];
        pbOutput[105] = pbInput[115];
        pbOutput[106] = pbInput[126];
        pbOutput[107] = pbInput[139];
        pbOutput[108] = pbInput[150];
        pbOutput[109] = pbInput[163];
        pbOutput[110] = pbInput[174];
        pbOutput[111] = pbInput[187];
        pbOutput[112] = pbInput[7];
        pbOutput[113] = pbInput[18];
        pbOutput[114] = pbInput[31];
        pbOutput[115] = pbInput[42];
        pbOutput[116] = pbInput[55];
        pbOutput[117] = pbInput[66];
        pbOutput[118] = pbInput[79];
        pbOutput[119] = pbInput[90];
        pbOutput[120] = pbInput[103];
        pbOutput[121] = pbInput[114];
        pbOutput[122] = pbInput[127];
        pbOutput[123] = pbInput[138];
        pbOutput[124] = pbInput[151];
        pbOutput[125] = pbInput[162];
        pbOutput[126] = pbInput[175];
        pbOutput[127] = pbInput[186];
        pbOutput[128] = pbInput[8];
        pbOutput[129] = pbInput[21];
        pbOutput[130] = pbInput[32];
        pbOutput[131] = pbInput[45];
        pbOutput[132] = pbInput[56];
        pbOutput[133] = pbInput[69];
        pbOutput[134] = pbInput[80];
        pbOutput[135] = pbInput[93];
        pbOutput[136] = pbInput[104];
        pbOutput[137] = pbInput[117];
        pbOutput[138] = pbInput[128];
        pbOutput[139] = pbInput[141];
        pbOutput[140] = pbInput[152];
        pbOutput[141] = pbInput[165];
        pbOutput[142] = pbInput[176];
        pbOutput[143] = pbInput[189];
        pbOutput[144] = pbInput[9];
        pbOutput[145] = pbInput[20];
        pbOutput[146] = pbInput[33];
        pbOutput[147] = pbInput[44];
        pbOutput[148] = pbInput[57];
        pbOutput[149] = pbInput[68];
        pbOutput[150] = pbInput[81];
        pbOutput[151] = pbInput[92];
        pbOutput[152] = pbInput[105];
        pbOutput[153] = pbInput[116];
        pbOutput[154] = pbInput[129];
        pbOutput[155] = pbInput[140];
        pbOutput[156] = pbInput[153];
        pbOutput[157] = pbInput[164];
        pbOutput[158] = pbInput[177];
        pbOutput[159] = pbInput[188];
        pbOutput[160] = pbInput[10];
        pbOutput[161] = pbInput[23];
        pbOutput[162] = pbInput[34];
        pbOutput[163] = pbInput[47];
        pbOutput[164] = pbInput[58];
        pbOutput[165] = pbInput[71];
        pbOutput[166] = pbInput[82];
        pbOutput[167] = pbInput[95];
        pbOutput[168] = pbInput[106];
        pbOutput[169] = pbInput[119];
        pbOutput[170] = pbInput[130];
        pbOutput[171] = pbInput[143];
        pbOutput[172] = pbInput[154];
        pbOutput[173] = pbInput[167];
        pbOutput[174] = pbInput[178];
        pbOutput[175] = pbInput[191];
        pbOutput[176] = pbInput[11];
        pbOutput[177] = pbInput[22];
        pbOutput[178] = pbInput[35];
        pbOutput[179] = pbInput[46];
        pbOutput[180] = pbInput[59];
        pbOutput[181] = pbInput[70];
        pbOutput[182] = pbInput[83];
        pbOutput[183] = pbInput[94];
        pbOutput[184] = pbInput[107];
        pbOutput[185] = pbInput[118];
        pbOutput[186] = pbInput[131];
        pbOutput[187] = pbInput[142];
        pbOutput[188] = pbInput[155];
        pbOutput[189] = pbInput[166];
        pbOutput[190] = pbInput[179];
        pbOutput[191] = pbInput[190];
	}
	
    BOOL_FUNC_PROCESS(ipin)
    {
        while (ipin.check_read())
        {
            const uchar*  input = ipin.peek();
            uchar*  output = opin().append();

			deinterleaver ( input, output );

            ipin.pop();
			Next()->Process(opin());
        }
        return true;
    }
};

DEFINE_LOCAL_CONTEXT(T11aDeinterleaveQAM64, CF_VOID);
template<TFILTER_ARGS>
class T11aDeinterleaveQAM64 : public TFilter<TFILTER_PARAMS>
{
public:
    DEFINE_IPORT(uchar, 288);
    DEFINE_OPORT(uchar, 288); // each bit is one 8-bit soft-value

public:
    REFERENCE_LOCAL_CONTEXT(T11aDeinterleaveQAM64);

    STD_TFILTER_CONSTRUCTOR(T11aDeinterleaveQAM64)
    { }

	FINL void deinterleaver ( const uchar * pbInput, uchar* pbOutput ) {
        pbOutput[0] = pbInput[0];
        pbOutput[1] = pbInput[20];
        pbOutput[2] = pbInput[37];
        pbOutput[3] = pbInput[54];
        pbOutput[4] = pbInput[74];
        pbOutput[5] = pbInput[91];
        pbOutput[6] = pbInput[108];
        pbOutput[7] = pbInput[128];
        pbOutput[8] = pbInput[145];
        pbOutput[9] = pbInput[162];
        pbOutput[10] = pbInput[182];
        pbOutput[11] = pbInput[199];
        pbOutput[12] = pbInput[216];
        pbOutput[13] = pbInput[236];
        pbOutput[14] = pbInput[253];
        pbOutput[15] = pbInput[270];
        pbOutput[16] = pbInput[1];
        pbOutput[17] = pbInput[18];
        pbOutput[18] = pbInput[38];
        pbOutput[19] = pbInput[55];
        pbOutput[20] = pbInput[72];
        pbOutput[21] = pbInput[92];
        pbOutput[22] = pbInput[109];
        pbOutput[23] = pbInput[126];
        pbOutput[24] = pbInput[146];
        pbOutput[25] = pbInput[163];
        pbOutput[26] = pbInput[180];
        pbOutput[27] = pbInput[200];
        pbOutput[28] = pbInput[217];
        pbOutput[29] = pbInput[234];
        pbOutput[30] = pbInput[254];
        pbOutput[31] = pbInput[271];
        pbOutput[32] = pbInput[2];
        pbOutput[33] = pbInput[19];
        pbOutput[34] = pbInput[36];
        pbOutput[35] = pbInput[56];
        pbOutput[36] = pbInput[73];
        pbOutput[37] = pbInput[90];
        pbOutput[38] = pbInput[110];
        pbOutput[39] = pbInput[127];
        pbOutput[40] = pbInput[144];
        pbOutput[41] = pbInput[164];
        pbOutput[42] = pbInput[181];
        pbOutput[43] = pbInput[198];
        pbOutput[44] = pbInput[218];
        pbOutput[45] = pbInput[235];
        pbOutput[46] = pbInput[252];
        pbOutput[47] = pbInput[272];
        pbOutput[48] = pbInput[3];
        pbOutput[49] = pbInput[23];
        pbOutput[50] = pbInput[40];
        pbOutput[51] = pbInput[57];
        pbOutput[52] = pbInput[77];
        pbOutput[53] = pbInput[94];
        pbOutput[54] = pbInput[111];
        pbOutput[55] = pbInput[131];
        pbOutput[56] = pbInput[148];
        pbOutput[57] = pbInput[165];
        pbOutput[58] = pbInput[185];
        pbOutput[59] = pbInput[202];
        pbOutput[60] = pbInput[219];
        pbOutput[61] = pbInput[239];
        pbOutput[62] = pbInput[256];
        pbOutput[63] = pbInput[273];
        pbOutput[64] = pbInput[4];
        pbOutput[65] = pbInput[21];
        pbOutput[66] = pbInput[41];
        pbOutput[67] = pbInput[58];
        pbOutput[68] = pbInput[75];
        pbOutput[69] = pbInput[95];
        pbOutput[70] = pbInput[112];
        pbOutput[71] = pbInput[129];
        pbOutput[72] = pbInput[149];
        pbOutput[73] = pbInput[166];
        pbOutput[74] = pbInput[183];
        pbOutput[75] = pbInput[203];
        pbOutput[76] = pbInput[220];
        pbOutput[77] = pbInput[237];
        pbOutput[78] = pbInput[257];
        pbOutput[79] = pbInput[274];
        pbOutput[80] = pbInput[5];
        pbOutput[81] = pbInput[22];
        pbOutput[82] = pbInput[39];
        pbOutput[83] = pbInput[59];
        pbOutput[84] = pbInput[76];
        pbOutput[85] = pbInput[93];
        pbOutput[86] = pbInput[113];
        pbOutput[87] = pbInput[130];
        pbOutput[88] = pbInput[147];
        pbOutput[89] = pbInput[167];
        pbOutput[90] = pbInput[184];
        pbOutput[91] = pbInput[201];
        pbOutput[92] = pbInput[221];
        pbOutput[93] = pbInput[238];
        pbOutput[94] = pbInput[255];
        pbOutput[95] = pbInput[275];
        pbOutput[96] = pbInput[6];
        pbOutput[97] = pbInput[26];
        pbOutput[98] = pbInput[43];
        pbOutput[99] = pbInput[60];
        pbOutput[100] = pbInput[80];
        pbOutput[101] = pbInput[97];
        pbOutput[102] = pbInput[114];
        pbOutput[103] = pbInput[134];
        pbOutput[104] = pbInput[151];
        pbOutput[105] = pbInput[168];
        pbOutput[106] = pbInput[188];
        pbOutput[107] = pbInput[205];
        pbOutput[108] = pbInput[222];
        pbOutput[109] = pbInput[242];
        pbOutput[110] = pbInput[259];
        pbOutput[111] = pbInput[276];
        pbOutput[112] = pbInput[7];
        pbOutput[113] = pbInput[24];
        pbOutput[114] = pbInput[44];
        pbOutput[115] = pbInput[61];
        pbOutput[116] = pbInput[78];
        pbOutput[117] = pbInput[98];
        pbOutput[118] = pbInput[115];
        pbOutput[119] = pbInput[132];
        pbOutput[120] = pbInput[152];
        pbOutput[121] = pbInput[169];
        pbOutput[122] = pbInput[186];
        pbOutput[123] = pbInput[206];
        pbOutput[124] = pbInput[223];
        pbOutput[125] = pbInput[240];
        pbOutput[126] = pbInput[260];
        pbOutput[127] = pbInput[277];
        pbOutput[128] = pbInput[8];
        pbOutput[129] = pbInput[25];
        pbOutput[130] = pbInput[42];
        pbOutput[131] = pbInput[62];
        pbOutput[132] = pbInput[79];
        pbOutput[133] = pbInput[96];
        pbOutput[134] = pbInput[116];
        pbOutput[135] = pbInput[133];
        pbOutput[136] = pbInput[150];
        pbOutput[137] = pbInput[170];
        pbOutput[138] = pbInput[187];
        pbOutput[139] = pbInput[204];
        pbOutput[140] = pbInput[224];
        pbOutput[141] = pbInput[241];
        pbOutput[142] = pbInput[258];
        pbOutput[143] = pbInput[278];
        pbOutput[144] = pbInput[9];
        pbOutput[145] = pbInput[29];
        pbOutput[146] = pbInput[46];
        pbOutput[147] = pbInput[63];
        pbOutput[148] = pbInput[83];
        pbOutput[149] = pbInput[100];
        pbOutput[150] = pbInput[117];
        pbOutput[151] = pbInput[137];
        pbOutput[152] = pbInput[154];
        pbOutput[153] = pbInput[171];
        pbOutput[154] = pbInput[191];
        pbOutput[155] = pbInput[208];
        pbOutput[156] = pbInput[225];
        pbOutput[157] = pbInput[245];
        pbOutput[158] = pbInput[262];
        pbOutput[159] = pbInput[279];
        pbOutput[160] = pbInput[10];
        pbOutput[161] = pbInput[27];
        pbOutput[162] = pbInput[47];
        pbOutput[163] = pbInput[64];
        pbOutput[164] = pbInput[81];
        pbOutput[165] = pbInput[101];
        pbOutput[166] = pbInput[118];
        pbOutput[167] = pbInput[135];
        pbOutput[168] = pbInput[155];
        pbOutput[169] = pbInput[172];
        pbOutput[170] = pbInput[189];
        pbOutput[171] = pbInput[209];
        pbOutput[172] = pbInput[226];
        pbOutput[173] = pbInput[243];
        pbOutput[174] = pbInput[263];
        pbOutput[175] = pbInput[280];
        pbOutput[176] = pbInput[11];
        pbOutput[177] = pbInput[28];
        pbOutput[178] = pbInput[45];
        pbOutput[179] = pbInput[65];
        pbOutput[180] = pbInput[82];
        pbOutput[181] = pbInput[99];
        pbOutput[182] = pbInput[119];
        pbOutput[183] = pbInput[136];
        pbOutput[184] = pbInput[153];
        pbOutput[185] = pbInput[173];
        pbOutput[186] = pbInput[190];
        pbOutput[187] = pbInput[207];
        pbOutput[188] = pbInput[227];
        pbOutput[189] = pbInput[244];
        pbOutput[190] = pbInput[261];
        pbOutput[191] = pbInput[281];
        pbOutput[192] = pbInput[12];
        pbOutput[193] = pbInput[32];
        pbOutput[194] = pbInput[49];
        pbOutput[195] = pbInput[66];
        pbOutput[196] = pbInput[86];
        pbOutput[197] = pbInput[103];
        pbOutput[198] = pbInput[120];
        pbOutput[199] = pbInput[140];
        pbOutput[200] = pbInput[157];
        pbOutput[201] = pbInput[174];
        pbOutput[202] = pbInput[194];
        pbOutput[203] = pbInput[211];
        pbOutput[204] = pbInput[228];
        pbOutput[205] = pbInput[248];
        pbOutput[206] = pbInput[265];
        pbOutput[207] = pbInput[282];
        pbOutput[208] = pbInput[13];
        pbOutput[209] = pbInput[30];
        pbOutput[210] = pbInput[50];
        pbOutput[211] = pbInput[67];
        pbOutput[212] = pbInput[84];
        pbOutput[213] = pbInput[104];
        pbOutput[214] = pbInput[121];
        pbOutput[215] = pbInput[138];
        pbOutput[216] = pbInput[158];
        pbOutput[217] = pbInput[175];
        pbOutput[218] = pbInput[192];
        pbOutput[219] = pbInput[212];
        pbOutput[220] = pbInput[229];
        pbOutput[221] = pbInput[246];
        pbOutput[222] = pbInput[266];
        pbOutput[223] = pbInput[283];
        pbOutput[224] = pbInput[14];
        pbOutput[225] = pbInput[31];
        pbOutput[226] = pbInput[48];
        pbOutput[227] = pbInput[68];
        pbOutput[228] = pbInput[85];
        pbOutput[229] = pbInput[102];
        pbOutput[230] = pbInput[122];
        pbOutput[231] = pbInput[139];
        pbOutput[232] = pbInput[156];
        pbOutput[233] = pbInput[176];
        pbOutput[234] = pbInput[193];
        pbOutput[235] = pbInput[210];
        pbOutput[236] = pbInput[230];
        pbOutput[237] = pbInput[247];
        pbOutput[238] = pbInput[264];
        pbOutput[239] = pbInput[284];
        pbOutput[240] = pbInput[15];
        pbOutput[241] = pbInput[35];
        pbOutput[242] = pbInput[52];
        pbOutput[243] = pbInput[69];
        pbOutput[244] = pbInput[89];
        pbOutput[245] = pbInput[106];
        pbOutput[246] = pbInput[123];
        pbOutput[247] = pbInput[143];
        pbOutput[248] = pbInput[160];
        pbOutput[249] = pbInput[177];
        pbOutput[250] = pbInput[197];
        pbOutput[251] = pbInput[214];
        pbOutput[252] = pbInput[231];
        pbOutput[253] = pbInput[251];
        pbOutput[254] = pbInput[268];
        pbOutput[255] = pbInput[285];
        pbOutput[256] = pbInput[16];
        pbOutput[257] = pbInput[33];
        pbOutput[258] = pbInput[53];
        pbOutput[259] = pbInput[70];
        pbOutput[260] = pbInput[87];
        pbOutput[261] = pbInput[107];
        pbOutput[262] = pbInput[124];
        pbOutput[263] = pbInput[141];
        pbOutput[264] = pbInput[161];
        pbOutput[265] = pbInput[178];
        pbOutput[266] = pbInput[195];
        pbOutput[267] = pbInput[215];
        pbOutput[268] = pbInput[232];
        pbOutput[269] = pbInput[249];
        pbOutput[270] = pbInput[269];
        pbOutput[271] = pbInput[286];
        pbOutput[272] = pbInput[17];
        pbOutput[273] = pbInput[34];
        pbOutput[274] = pbInput[51];
        pbOutput[275] = pbInput[71];
        pbOutput[276] = pbInput[88];
        pbOutput[277] = pbInput[105];
        pbOutput[278] = pbInput[125];
        pbOutput[279] = pbInput[142];
        pbOutput[280] = pbInput[159];
        pbOutput[281] = pbInput[179];
        pbOutput[282] = pbInput[196];
        pbOutput[283] = pbInput[213];
        pbOutput[284] = pbInput[233];
        pbOutput[285] = pbInput[250];
        pbOutput[286] = pbInput[267];
        pbOutput[287] = pbInput[287];
	}
	
    BOOL_FUNC_PROCESS(ipin)
    {
        while (ipin.check_read())
        {
            const uchar*  input = ipin.peek();
            uchar*  output = opin().append();

			deinterleaver ( input, output );

            ipin.pop();
			Next()->Process(opin());
        }
        return true;
    }
};
