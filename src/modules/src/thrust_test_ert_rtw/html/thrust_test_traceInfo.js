function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "thrust_test"};
	this.sidHashMap["thrust_test"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/thrust"] = {sid: "thrust_test:1"};
	this.sidHashMap["thrust_test:1"] = {rtwname: "<Root>/thrust"};
	this.rtwnameHashMap["<Root>/Data Type Conversion"] = {sid: "thrust_test:2"};
	this.sidHashMap["thrust_test:2"] = {rtwname: "<Root>/Data Type Conversion"};
	this.rtwnameHashMap["<Root>/Saturation"] = {sid: "thrust_test:3"};
	this.sidHashMap["thrust_test:3"] = {rtwname: "<Root>/Saturation"};
	this.rtwnameHashMap["<Root>/M1_output"] = {sid: "thrust_test:5"};
	this.sidHashMap["thrust_test:5"] = {rtwname: "<Root>/M1_output"};
	this.rtwnameHashMap["<Root>/M2_output"] = {sid: "thrust_test:6"};
	this.sidHashMap["thrust_test:6"] = {rtwname: "<Root>/M2_output"};
	this.rtwnameHashMap["<Root>/M3_output"] = {sid: "thrust_test:7"};
	this.sidHashMap["thrust_test:7"] = {rtwname: "<Root>/M3_output"};
	this.rtwnameHashMap["<Root>/M4_output"] = {sid: "thrust_test:8"};
	this.sidHashMap["thrust_test:8"] = {rtwname: "<Root>/M4_output"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
