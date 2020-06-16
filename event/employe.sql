--------------------------------------------------------
--  Fichier créé - mardi-avril-28-2020   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table EMPLOYE
--------------------------------------------------------

  CREATE TABLE "IHEB"."EMPLOYE" 
   (	"NOM_EMPLOYE" VARCHAR2(20 BYTE), 
	"MDP_EMPLOYE" VARCHAR2(20 BYTE), 
	"POSTE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into IHEB.EMPLOYE
SET DEFINE OFF;
Insert into IHEB.EMPLOYE (NOM_EMPLOYE,MDP_EMPLOYE,POSTE) values ('iheb','123','Agent des evenements');
