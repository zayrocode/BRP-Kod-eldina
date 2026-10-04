#if defined _balkan_extras_included
    #endinput
#endif
#define _balkan_extras_included

#define TEMP_NAME_REGISTRY "BalkanRP/PrivremenaImena.ini"
#define MAX_TEMP_NAME_RECORDS 500
#define TEMP_NAME_BACKUP_DIR "BackupImena"

stock ShowAH(playerid)
{
    new text[2048];
    strcat(text, "/mp3 /stats /help /dajadmin /setcodeadmin\n", sizeof(text));
    strcat(text, "/admini /adminduty /dajhelpera /hduty /helperi\n", sizeof(text));
    strcat(text, "/setcodehelper /napravikucu /izbrisikucu /editujkucu /jetpack\n", sizeof(text));
    strcat(text, "/buyhouse /gotohouse /sellhouse /lockhouse /unlockhouse\n", sizeof(text));
    strcat(text, "/napravimarket /editujmarket /obrisimarket /buybizz /sellbizz\n", sizeof(text));
    strcat(text, "/gotomarket /kick /ban /setlevel /unbanip\n", sizeof(text));
    strcat(text, "/gotopos /kupitelefon /kupibrojtel /kupislusalice /lideri\n", sizeof(text));
    strcat(text, "/inventory /buyinventory /kupi /smsad /napravioglase\n", sizeof(text));
    strcat(text, "/editujoglase /obrisioglase /napravizlataru /editujzlataru /obrisizlataru\n", sizeof(text));
    strcat(text, "/kupizlato /prodajzlato /kupisat /time /setleader\n", sizeof(text));
    strcat(text, "/slap /l /gethere /b /me\n", sizeof(text));
    strcat(text, "/do /member /invite /uninvite /orghelp\n", sizeof(text));
    strcat(text, "/kazniclana /napravitrafiku /editujtrafiku /obrisitrafiku /kreirajobjekat\n", sizeof(text));
    strcat(text, "/editujobjekt /obrisiobjekat /trafika /kreirajlabeltrafika /obrisilabeltrafika\n", sizeof(text));
    strcat(text, "/kreirajlabel /obrisilabel /givemoney /restart /rac\n", sizeof(text));
    strcat(text, "/call /acceptfaren /duty /f /d\n", sizeof(text));
    strcat(text, "/ooc /giverank /preuzmivozilo /bigear /veh\n", sizeof(text));
    strcat(text, "/posao /otkaz /jobhelp /engine /dovezipostu\n", sizeof(text));
    strcat(text, "/prekiniposao /sethealth /setarmour /uninviteme /stablo\n", sizeof(text));
    strcat(text, "/sethour /setminute /ah /name\n", sizeof(text));
    ShowPlayerDialog(playerid, DIALOG_AH, DIALOG_STYLE_MSGBOX, "Sve komande", text, "Zatvori", "");
    return 1;
}

CMD:ah(playerid, params[])
{
    return ShowAH(playerid);
}

forward CheckTemporaryNames();

stock TempNameKey(key[], size, slot, const field[])
{
    format(key, size, "Name_%d_%s", slot, field);
    return 1;
}

stock TempNameCount()
{
    if(!DOF2_FileExists(TEMP_NAME_REGISTRY)) return 0;
    new count = DOF2_GetInt(TEMP_NAME_REGISTRY, "Count");
    if(count < 0) return 0;
    if(count > MAX_TEMP_NAME_RECORDS) return MAX_TEMP_NAME_RECORDS;
    return count;
}

stock GetTempNameRecord(slot, original[], current[], &expires, &active)
{
    new key[48];
    TempNameKey(key, sizeof(key), slot, "Original");
    if(!DOF2_IsSet(TEMP_NAME_REGISTRY, key)) return 0;
    format(original, MAX_PLAYER_NAME, "%s", DOF2_GetString(TEMP_NAME_REGISTRY, key));
    TempNameKey(key, sizeof(key), slot, "Current");
    format(current, MAX_PLAYER_NAME, "%s", DOF2_GetString(TEMP_NAME_REGISTRY, key));
    TempNameKey(key, sizeof(key), slot, "Expires");
    expires = DOF2_GetInt(TEMP_NAME_REGISTRY, key);
    TempNameKey(key, sizeof(key), slot, "Active");
    active = DOF2_GetInt(TEMP_NAME_REGISTRY, key);
    return 1;
}

stock SaveNameBackup(const original[], const current[], expires, active)
{
    new file[128], oldname[MAX_PLAYER_NAME], tempname[MAX_PLAYER_NAME];
    format(file, sizeof(file), "%s/%s.ini", TEMP_NAME_BACKUP_DIR, original);
    if(!DOF2_FileExists(file) && !DOF2_CreateFile(file)) return 0;
    format(oldname, sizeof(oldname), "%s", original);
    format(tempname, sizeof(tempname), "%s", current);
    DOF2_SetString(file, "OriginalName", oldname);
    DOF2_SetString(file, "TemporaryName", tempname);
    DOF2_SetInt(file, "Expires", expires);
    DOF2_SetInt(file, "Active", active);
    if(!active) DOF2_SetInt(file, "RestoredAt", gettime());
    else DOF2_SetInt(file, "RestoredAt", 0);
    DOF2_SaveFile();
    return 1;
}

stock SetTempNameActive(slot, active)
{
    new key[48];
    TempNameKey(key, sizeof(key), slot, "Active");
    DOF2_SetInt(TEMP_NAME_REGISTRY, key, active);
    DOF2_SaveFile();
    return 1;
}

stock UpdateNameReferences(const oldname[], const newname[])
{
    new file[128], key[40], value[MAX_PLAYER_NAME];

    for(new i = 0; i < MAX_KUCA; i++)
    {
        if(strcmp(HouseInfo[i][kOwner], oldname, true) != 0) continue;
        format(HouseInfo[i][kOwner], MAX_PLAYER_NAME, "%s", newname);
        SaveHouse(i);
        UpdateHouseCP(i);
    }
    for(new i = 0; i < MAX_MARKETA; i++)
    {
        if(strcmp(MarketInfo[i][mOwner], oldname, true) != 0) continue;
        format(MarketInfo[i][mOwner], MAX_PLAYER_NAME, "%s", newname);
        SaveMarket(i);
        UpdateMarketCP(i);
    }
    for(new i = 0; i < MAX_OGLASA; i++)
    {
        if(strcmp(OglasiInfo[i][oOwner], oldname, true) != 0) continue;
        format(OglasiInfo[i][oOwner], MAX_PLAYER_NAME, "%s", newname);
        SaveOglase(i);
        UpdateOglaseCP(i);
    }
    for(new i = 0; i < MAX_ZLATA; i++)
    {
        if(strcmp(ZlataInfo[i][zOwner], oldname, true) != 0) continue;
        format(ZlataInfo[i][zOwner], MAX_PLAYER_NAME, "%s", newname);
        SaveZlataru(i);
        UpdateZlataruCP(i);
    }
    for(new i = 0; i < MAX_TRAFIKE; i++)
    {
        if(strcmp(TrafikaInfo[i][tOwner], oldname, true) != 0) continue;
        format(TrafikaInfo[i][tOwner], MAX_PLAYER_NAME, "%s", newname);
        SaveTrafiku(i);
        UpdateTrafikuCP(i);
    }

    format(file, sizeof(file), "BalkanRP/Lideri.ini");
    if(DOF2_FileExists(file))
    {
        new changed = 0;
        for(new i = 1; i <= 19; i++)
        {
            format(key, sizeof(key), "Lider_%d", i);
            if(!DOF2_IsSet(file, key)) continue;
            format(value, sizeof(value), "%s", DOF2_GetString(file, key));
            if(strcmp(value, oldname, true) != 0) continue;
            format(value, sizeof(value), "%s", newname);
            DOF2_SetString(file, key, value);
            changed = 1;
        }
        if(changed) DOF2_SaveFile();
    }

    for(new org = 1; org <= 19; org++)
    {
        format(file, sizeof(file), "BalkanRP/Org_%d.ini", org);
        if(!DOF2_FileExists(file)) continue;
        new changed = 0;
        for(new slot = 0; slot < 30; slot++)
        {
            format(key, sizeof(key), "Slot_%d", slot);
            if(!DOF2_IsSet(file, key)) continue;
            format(value, sizeof(value), "%s", DOF2_GetString(file, key));
            if(strcmp(value, oldname, true) != 0) continue;
            format(value, sizeof(value), "%s", newname);
            DOF2_SetString(file, key, value);
            changed = 1;
        }
        if(changed) DOF2_SaveFile();
    }
    return 1;
}

stock RestoreTempNameSlot(slot)
{
    new original[MAX_PLAYER_NAME], current[MAX_PLAYER_NAME], expires, active;
    if(!GetTempNameRecord(slot, original, current, expires, active) || !active) return 0;

    new currentfile[128], originalfile[128];
    format(currentfile, sizeof(currentfile), "Korisnici/%s.ini", current);
    format(originalfile, sizeof(originalfile), "Korisnici/%s.ini", original);

    if(!DOF2_FileExists(currentfile))
    {
        if(!DOF2_FileExists(originalfile)) return 0;
        UpdateNameReferences(current, original);
        SetTempNameActive(slot, 0);
        SaveNameBackup(original, current, expires, 0);
        return 1;
    }
    if(DOF2_FileExists(originalfile)) return 0;

    new online = INVALID_PLAYER_ID, name[MAX_PLAYER_NAME];
    for(new p = 0; p < MAX_PLAYERS; p++)
    {
        if(!IsPlayerConnected(p)) continue;
        GetPlayerName(p, name, sizeof(name));
        if(strcmp(name, current, true) == 0) { online = p; break; }
    }
    if(online != INVALID_PLAYER_ID && SetPlayerName(online, original) != 1) return 0;
    if(online != INVALID_PLAYER_ID && GetPVarInt(online, "BR_LoggedIn"))
    {
        DOF2_SetInt(currentfile, "Novac", GetPlayerMoney(online));
        DOF2_SaveFile();
    }
    if(!DOF2_RenameFile(currentfile, originalfile))
    {
        if(online != INVALID_PLAYER_ID) SetPlayerName(online, current);
        return 0;
    }

    DOF2_SetInt(originalfile, "NameExpires", 0);
    DOF2_SaveFile();
    UpdateNameReferences(current, original);
    SetTempNameActive(slot, 0);
    SaveNameBackup(original, current, expires, 0);
    if(online != INVALID_PLAYER_ID)
        SendClientMessage(online, 0x00BFFFFF, "[IME]: Privremeno ime je isteklo. Vraceno vam je registrovano ime.");
    return 1;
}

public CheckTemporaryNames()
{
    new count = TempNameCount();
    for(new i = 0; i < count; i++)
    {
        new original[MAX_PLAYER_NAME], current[MAX_PLAYER_NAME], expires, active;
        if(!GetTempNameRecord(i, original, current, expires, active)) continue;
        if(active && expires > 0 && gettime() >= expires) RestoreTempNameSlot(i);
    }
    return 1;
}

stock HandleTemporaryNameConnect(playerid, playername[])
{
    new count = TempNameCount();
    for(new i = count - 1; i >= 0; i--)
    {
        new original[MAX_PLAYER_NAME], current[MAX_PLAYER_NAME], expires, active;
        if(!GetTempNameRecord(i, original, current, expires, active)) continue;
        new matches_original = strcmp(playername, original, true) == 0;
        new matches_current = strcmp(playername, current, true) == 0;
        if(!matches_original && !matches_current) continue;

        if(active && expires > 0 && gettime() >= expires)
        {
            if(!RestoreTempNameSlot(i) && matches_original)
            {
                SendClientMessage(playerid, 0xFF0000FF, "[IME]: Nalog trenutno ne moze vratiti staro ime. Kontaktirajte administratora.");
                SetTimerEx("KickPlayerDelayed", 500, false, "i", playerid);
                return 0;
            }
            GetPlayerName(playerid, playername, MAX_PLAYER_NAME);
            return 1;
        }
        if(active && matches_original)
        {
            new message[128];
            format(message, sizeof(message), "[IME]: Privremeno ime vam je %s. Prijavite se pod tim imenom.", current);
            SendClientMessage(playerid, 0xFF0000FF, message);
            SetTimerEx("KickPlayerDelayed", 500, false, "i", playerid);
            return 0;
        }
        if(!active && matches_current)
        {
            new accountfile[128];
            format(accountfile, sizeof(accountfile), "Korisnici/%s.ini", original);
            if(!DOF2_FileExists(accountfile) || SetPlayerName(playerid, original) != 1)
            {
                SendClientMessage(playerid, 0xFF0000FF, "[IME]: Prijavite se sa registrovanim imenom.");
                SetTimerEx("KickPlayerDelayed", 500, false, "i", playerid);
                return 0;
            }
            GetPlayerName(playerid, playername, MAX_PLAYER_NAME);
        }
        return 1;
    }
    return 1;
}

CMD:name(playerid, params[])
{
    new adminname[MAX_PLAYER_NAME], adminfile[128];
    GetPlayerName(playerid, adminname, sizeof(adminname));
    format(adminfile, sizeof(adminfile), "Korisnici/%s.ini", adminname);
    new adminlevel = DOF2_FileExists(adminfile) ? DOF2_GetInt(adminfile, "Admin") : 0;
    if(adminlevel < 9 && !IsPlayerAdmin(playerid))
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Samo Vlasnik ili RCON admin moze koristiti /name.");

    new targetid, days, desired[MAX_PLAYER_NAME];
    if(sscanf(params, "us[24]d", targetid, desired, days))
        return SendClientMessage(playerid, 0x00BFFFFF, "Koristenje: /name [ID/Ime] [NovoIme] [Broj dana]");
    if(!IsPlayerConnected(targetid))
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Igrac nije online.");
    if(days < 1 || days > 365)
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Broj dana mora biti od 1 do 365.");

    if(!GetPVarInt(targetid, "BR_LoggedIn"))
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Sacekajte da se igrac prijavi na nalog.");

    new oldcurrent[MAX_PLAYER_NAME], original[MAX_PLAYER_NAME];
    GetPlayerName(targetid, oldcurrent, sizeof(oldcurrent));
    new length = strlen(desired);
    if(length < 3 || length > 20 || desired[0] < 'A' || desired[0] > 'Z')
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Novo ime mora imati 3-20 slova i poceti velikim slovom.");
    for(new i = 0; i < length; i++)
    {
        if(!((desired[i] >= 'A' && desired[i] <= 'Z') || (desired[i] >= 'a' && desired[i] <= 'z')))
            return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Novo ime smije sadrzati samo slova.");
    }

    new oldfile[128], newfile[128];
    format(oldfile, sizeof(oldfile), "Korisnici/%s.ini", oldcurrent);
    format(newfile, sizeof(newfile), "Korisnici/%s.ini", desired);
    if(!DOF2_FileExists(oldfile))
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Nalog igraca nije pronadjen.");
    new same_name = strcmp(oldcurrent, desired, true) == 0;
    if(!same_name && DOF2_FileExists(newfile))
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Kratko ime vec koristi drugi nalog.");

    new name[MAX_PLAYER_NAME];
    for(new p = 0; p < MAX_PLAYERS; p++)
    {
        if(!IsPlayerConnected(p) || p == targetid) continue;
        GetPlayerName(p, name, sizeof(name));
        if(strcmp(name, desired, true) == 0)
            return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Kratko ime vec koristi drugi igrac.");
    }

    if(!DOF2_FileExists(TEMP_NAME_REGISTRY)) DOF2_CreateFile(TEMP_NAME_REGISTRY);
    if(!DOF2_FileExists(TEMP_NAME_REGISTRY))
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Ne mogu otvoriti evidenciju privremenih imena.");

    new count = TempNameCount(), slot = count, active_slot = -1;
    for(new i = 0; i < count; i++)
    {
        new old[MAX_PLAYER_NAME], shortname[MAX_PLAYER_NAME], expires, active;
        if(!GetTempNameRecord(i, old, shortname, expires, active)) continue;
        if(active && strcmp(shortname, oldcurrent, true) == 0)
        {
            if(active_slot != -1)
                return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Dupla evidencija imena. Kontaktirajte administratora.");
            active_slot = i;
            format(original, sizeof(original), "%s", old);
        }
    }
    if(active_slot != -1) slot = active_slot;
    else
    {
        if(strfind(oldcurrent, "_") < 0)
            return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Igrac nema registrovano RP ime.");
        format(original, sizeof(original), "%s", oldcurrent);
    }
    for(new i = 0; i < count; i++)
    {
        new old[MAX_PLAYER_NAME], shortname[MAX_PLAYER_NAME], expires, active;
        if(!GetTempNameRecord(i, old, shortname, expires, active)) continue;
        if(i != active_slot && strcmp(shortname, desired, true) == 0 && strcmp(old, original, true) != 0)
            return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Kratko ime je rezervisano za drugi nalog.");
        if(i != active_slot && active && (strcmp(old, original, true) == 0 || strcmp(shortname, desired, true) == 0))
            return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Evidencija imena je vec aktivna.");
        if(active_slot == -1 && !active && strcmp(old, original, true) == 0) slot = i;
    }
    if(slot >= MAX_TEMP_NAME_RECORDS)
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Evidencija privremenih imena je puna.");

    new originalfile[128];
    format(originalfile, sizeof(originalfile), "Korisnici/%s.ini", original);
    if(active_slot != -1 && DOF2_FileExists(originalfile))
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Stari nalog ima dupli fajl. Kontaktirajte administratora.");

    new backupfile[128];
    format(backupfile, sizeof(backupfile), "%s/%s.ini", TEMP_NAME_BACKUP_DIR, original);
    if(!DOF2_FileExists(backupfile) && !DOF2_CreateFile(backupfile))
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Ne mogu napraviti backup starog imena.");

    DOF2_SetInt(oldfile, "Novac", GetPlayerMoney(targetid));
    DOF2_SaveFile();
    if(!same_name && SetPlayerName(targetid, desired) != 1)
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Promjena imena u igri nije uspjela.");
    if(!same_name && !DOF2_RenameFile(oldfile, newfile))
    {
        SetPlayerName(targetid, oldcurrent);
        return SendClientMessage(playerid, 0xFF0000FF, "[IME]: Promjena fajla naloga nije uspjela.");
    }

    new expires = gettime() + days * 86400, key[48];
    DOF2_SetString(newfile, "NameOriginal", original);
    DOF2_SetInt(newfile, "NameExpires", expires);
    DOF2_SaveFile();
    if(!same_name) UpdateNameReferences(oldcurrent, desired);

    TempNameKey(key, sizeof(key), slot, "Original"); DOF2_SetString(TEMP_NAME_REGISTRY, key, original);
    TempNameKey(key, sizeof(key), slot, "Current"); DOF2_SetString(TEMP_NAME_REGISTRY, key, desired);
    TempNameKey(key, sizeof(key), slot, "Expires"); DOF2_SetInt(TEMP_NAME_REGISTRY, key, expires);
    TempNameKey(key, sizeof(key), slot, "Active"); DOF2_SetInt(TEMP_NAME_REGISTRY, key, 1);
    if(slot == count) DOF2_SetInt(TEMP_NAME_REGISTRY, "Count", count + 1);
    DOF2_SaveFile();
    SaveNameBackup(original, desired, expires, 1);

    new message[160];
    format(message, sizeof(message), "[IME]: Vase ime je sada %s na %d dana. Pod ovim imenom se prijavite sljedeci put.", desired, days);
    SendClientMessage(targetid, 0x00BFFFFF, message);
    format(message, sizeof(message), "[IME]: Ime %s je promijenjeno u %s na %d dana.", oldcurrent, desired, days);
    SendClientMessage(playerid, 0x00BFFFFF, message);
    return 1;
}
