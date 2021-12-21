using System;

namespace Reports.DAL.Entities
{
    public class Employee
    {
        public Guid Id { get; private init; }

        public string Name { get; private init; }
        public Guid BossId { get; private init; }
        private Employee()
        {
        }
        public Employee(string name, Guid bossId)
        {
            if (string.IsNullOrWhiteSpace(name))
            {
                throw new ArgumentNullException(nameof(name), "Name is invalid");
            }

            Id = new Guid();
            Name = name;
            BossId = bossId;
        }
    }
}