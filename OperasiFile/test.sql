-- insert ke Barang
INSERT INTO Barang VALUES
("A001", "Mama Lemon", "2020-04-11 16:54:16", "20"),
("A002", "Sabun", "2020-04-11 16:54:16", "10"),
("A003", "Shampo", "2020-04-11 16:54:16", "25"),
("A004", "Hair Conditioner", "2020-04-11 16:54:16", "18"),
("B001", "Pasta Gigi", "2020-04-21 16:54:16", "15"),
("B002", "Minyak", "2020-04-21 16:54:16", "8"),
("B003", "Beras", "2020-04-21 16:54:16", "12"),
("C001", "Makanan Ringan", "2021-05-11 16:54:16", "23"),
("C002", "Mie Instan", "2021-05-11 16:54:16", "21"),
("C003", "Minuman Dingin", "2021-05-11 16:54:16", "18");

INSERT INTO pelanggan VALUES
("001", "Ahmad Situkang"),
("002", "Geraldine Etok"),
("003", "Riski Asmr"),
("004", "Rizal Samurai"),
("005", "Giovial Udin"),
("006", "Wardana Sami"),
("007", "Ui Ucok"),
("008", "Silatuconsina"),
("009", "Gobed Albert"),
("010", "Jemes Ashure");

INSERT INTO pembelian VALUES
("001", "A002", "2021-05-01 16:54:16", "Ahmad Situkang", "2", "Singaraja"),
("002", "C002", "2021-05-02 16:54:16", "Geraldine Etok", "3", "Singaraja"),
("003", "B002", "2021-05-03 16:30:16", "Riski Asmr", "2", "Singaraja"),
("004", "B003", "2021-05-07 15:54:16", "Rizal Samurai", "1", "Singaraja"),
("005", "B001", "2021-05-07 15:40:16", "Giovial Udin", "1", "Singaraja"),
("006", "C003", "2021-05-09 15:40:16", "Wardana Sami", "2", "Singaraja"),
("007", "A002", "2021-05-10 15:40:16", "Ui Ucok", "2", "Singaraja"),
("008", "A003", "2021-05-11 14:54:16", "Silatuconsina", "1", "Singaraja"),
("009", "A003", "2021-05-11 14:30:16", "Gobed Albert", "2", "Singaraja"),
("010", "C001", "2021-05-11 13:20:16", "Jemes Ashure", "5", "Singaraja");

-- Buat VIEW
-- 1
CREATE VIEW vw_pembelian 
AS SELECT pembelian.id_pembeli, barang.nama_barang, 
pembelian.nama_pembeli, pembelian.tanggal_beli, 
pembelian.jumlah_pembelian
FROM pembelian,barang
WHERE pembelian.id_barang=barang.id_barang;

-- 2
CREATE VIEW vw_barang_dibeli 
AS SELECT barang.nama_barang, pembelian.nama_pembeli,
pembelian.tanggal_beli, pembelian.jumlah_pembelian
FROM pembelian
RIGHT JOIN barang
ON pembelian.id_barang=barang.id_barang;

-- IF
SELECT nama_barang,
IF (jumlah_pembelian > 3, "Populer", "Kurang Populer") 
AS kepopuleran 
FROM vw_pembelian;


-- IFNULL
SELECT IFNULL(
(SELECT jumlah_pembelian FROM vw_barang_dibeli
WHERE jumlah_pembelian="6"), "Tidak Ditemukan"
) AS "Hasil";


-- NULLIF 
SELECT NULLIF(
(SELECT nama_barang FROM barang
WHERE id_barang="A002"), "Sabun"
) AS "Hasil";

-- CASE
SELECT nama_barang, stok_barang,
CASE
WHEN stok_barang < 15 THEN "Tolong segera restok"
WHEN stok_barang >= 15 THEN "Belum saatnya restok"
END AS "Restok"
FROM barang;

-- TEMPORARY TABEL
CREATE TEMPORARY TABLE distributor (
kode_dis int,
nama_dis varchar(50),
alamat_dis varchar(50)
);