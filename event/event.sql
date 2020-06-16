--------------------------------------------------------
--  Fichier créé - dimanche-avril-05-2020   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table EVENT
--------------------------------------------------------

  CREATE TABLE "IHEB"."EVENT" 
   (	"ID_EVENT" VARCHAR2(20 BYTE), 
	"NB_PART_EVENT" VARCHAR2(20 BYTE), 
	"NOM_EVENT" VARCHAR2(50 BYTE), 
	"TYPE_EVENT" VARCHAR2(30 BYTE), 
	"DATE_EVENT" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into IHEB.EVENT
SET DEFINE OFF;
Insert into IHEB.EVENT (ID_EVENT,NB_PART_EVENT,NOM_EVENT,TYPE_EVENT,DATE_EVENT) values ('pp','50','pool party','party','23/09/2021');
