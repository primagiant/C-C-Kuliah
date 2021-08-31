delimiter //
create trigger add_alumni
BEFORE DELETE
    ON mhs FOR EACH ROW
BEGIN
    INSERT INTO alumni
    set nama = OLD.nama,
    alamat = OLD.alamat;
END//
delimiter ;