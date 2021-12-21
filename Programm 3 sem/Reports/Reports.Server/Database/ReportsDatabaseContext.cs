using Microsoft.EntityFrameworkCore;
using Reports.DAL.Entities;

namespace Reports.Server.Database
{
    public class ReportsDatabaseContext : DbContext
    {
        public ReportsDatabaseContext(DbContextOptions<ReportsDatabaseContext> options) : base(options)
        {
            // this.Database.EnsureDeleted();
            this.Database.EnsureCreated();
        }

        public DbSet<Employee> Employees { get; set; }

        public DbSet<TaskModel> Tasks { get; set; }
        public DbSet<Report> Reports { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Employee>().ToTable("Employees");
            modelBuilder.Entity<TaskModel>().ToTable("Tasks");
            modelBuilder.Entity<Report>().ToTable("Reports");
            base.OnModelCreating(modelBuilder);
        }
    }
}